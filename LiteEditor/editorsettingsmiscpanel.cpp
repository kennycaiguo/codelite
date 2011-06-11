//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : editorsettingsmiscpanel.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "editorsettingsmiscpanel.h"
#include "generalinfo.h"
#include "frame.h"
#include "manager.h"
#include "pluginmanager.h"
#include "file_logger.h"
#include "wx/wxprec.h"
#include <wx/intl.h>
#include <wx/fontmap.h>
#include "ctags_manager.h"

#ifdef __WXMSW__
#include <wx/msw/uxtheme.h>
#endif

EditorSettingsMiscPanel::EditorSettingsMiscPanel( wxWindow* parent )
	: EditorSettingsMiscBasePanel( parent )
	, TreeBookNode<EditorSettingsMiscPanel>()
	, m_restartRequired (false)
{
	GeneralInfo info = clMainFrame::Get()->GetFrameGeneralInfo();
	OptionsConfigPtr options = EditorConfigST::Get()->GetOptions();
	if (options->GetIconsSize() == 16) {
		m_toolbarIconSize->SetSelection(0);
	} else {
		m_toolbarIconSize->SetSelection(1);
	}

	m_checkBoxEnableMSWTheme->SetValue(options->GetMswTheme());
	m_useSingleToolbar->SetValue(!PluginManager::Get()->AllowToolbar());

	m_oldSetLocale = options->GetUseLocale();
	m_SetLocale->SetValue(m_oldSetLocale);
	m_oldpreferredLocale = options->GetPreferredLocale();
	// Load the available locales and feed them to the wxchoice
	int select = FindAvailableLocales();
	if (select != wxNOT_FOUND) {
		m_AvailableLocales->SetSelection(select);
	}


	wxArrayString astrEncodings;
	wxFontEncoding fontEnc;
	int iCurrSelId = 0;
	size_t iEncCnt = wxFontMapper::GetSupportedEncodingsCount();
	for (size_t i = 0; i < iEncCnt; i++) {
		fontEnc = wxFontMapper::GetEncoding(i);
		if (wxFONTENCODING_SYSTEM == fontEnc) { // skip system, it is changed to UTF-8 in optionsconfig
			continue;
		}
		astrEncodings.Add(wxFontMapper::GetEncodingName(fontEnc));
		if (fontEnc == options->GetFileFontEncoding()) {
			iCurrSelId = i;
		}
	}

	m_fileEncoding->Append(astrEncodings);
	m_fileEncoding->SetSelection(iCurrSelId);

	long single_instance(1);
	EditorConfigST::Get()->GetLongValue(wxT("SingleInstance"), single_instance);
	m_singleAppInstance->SetValue(single_instance ? true : false);

	long check(1);
	EditorConfigST::Get()->GetLongValue(wxT("CheckNewVersion"), check);
	m_versionCheckOnStartup->SetValue(check ? true : false);

	check = 1;
	EditorConfigST::Get()->GetLongValue(wxT("ShowFullPathInFrameTitle"), check);
	m_fullFilePath->SetValue(check ? true : false);

	bool showSplash = info.GetFlags() & CL_SHOW_SPLASH ? true : false;
	m_showSplashScreen->SetValue(showSplash);

	long max_items(10);
	EditorConfigST::Get()->GetLongValue(wxT("MaxItemsInFindReplaceDialog"), max_items);
	m_maxItemsFindReplace->SetValue(max_items);

	long maxTabs(15);
	EditorConfigST::Get()->GetLongValue(wxT("MaxOpenedTabs"), maxTabs);
	m_spinCtrlMaxOpenTabs->SetValue(maxTabs);

	// Set the logging verbosity
	long logVerbosity(FileLogger::Error);
	EditorConfigST::Get()->GetLongValue(wxT("LogVerbosity"), logVerbosity);
	m_choice4->SetStringSelection( FileLogger::GetVerbosityAsString(logVerbosity) );
}

void EditorSettingsMiscPanel::OnClearButtonClick( wxCommandEvent& )
{
	ManagerST::Get()->ClearWorkspaceHistory();
	clMainFrame::Get()->GetMainBook()->ClearFileHistory();
}

void EditorSettingsMiscPanel::Save(OptionsConfigPtr options)
{

	if (m_showSplashScreen->IsChecked()) {
		clMainFrame::Get()->SetFrameFlag(true, CL_SHOW_SPLASH);
	} else {
		clMainFrame::Get()->SetFrameFlag(false, CL_SHOW_SPLASH);
	}

	// Set the theme support.
	// This option requires a restart of codelite
	bool oldEnableMSWTheme = options->GetMswTheme();
	options->SetMswTheme(m_checkBoxEnableMSWTheme->IsChecked());
	if(oldEnableMSWTheme != m_checkBoxEnableMSWTheme->IsChecked()) {
		m_restartRequired = true;
	}

	EditorConfigST::Get()->SaveLongValue(wxT("SingleInstance"), m_singleAppInstance->IsChecked() ? 1 : 0);
	EditorConfigST::Get()->SaveLongValue(wxT("CheckNewVersion"), m_versionCheckOnStartup->IsChecked() ? 1 : 0);
	EditorConfigST::Get()->SaveLongValue(wxT("ShowFullPathInFrameTitle"), m_fullFilePath->IsChecked() ? 1 : 0);

	bool oldUseSingleToolbar = !PluginManager::Get()->AllowToolbar();
	EditorConfigST::Get()->SaveLongValue(wxT("UseSingleToolbar"), m_useSingleToolbar->IsChecked() ? 1 : 0);

	int value = m_maxItemsFindReplace->GetValue();
	if (value < 1 || value > 50) {
		value = 10;
	}

	EditorConfigST::Get()->SaveLongValue(wxT("MaxItemsInFindReplaceDialog"), value);
	EditorConfigST::Get()->SaveLongValue(wxT("MaxOpenedTabs"), m_spinCtrlMaxOpenTabs->GetValue());

	//check to see of the icon size was modified
	int oldIconSize(24);

	OptionsConfigPtr oldOptions = EditorConfigST::Get()->GetOptions();
	if (oldOptions) {
		oldIconSize = oldOptions->GetIconsSize();
	}

	int iconSize(24);
	if (m_toolbarIconSize->GetSelection() == 0) {
		iconSize = 16;
	}
	options->SetIconsSize(iconSize);

	bool setlocale = m_SetLocale->IsChecked();
	options->SetUseLocale(setlocale);
	wxString newLocaleString = m_AvailableLocales->GetStringSelection();
	// I don't think we should check if newLocaleString is empty; that's still useful information
	newLocaleString = newLocaleString.BeforeFirst(wxT(':')); // Store it as "fr_FR", not "fr_FR: French"
	options->SetPreferredLocale(newLocaleString);
	if ((setlocale != m_oldSetLocale) || (newLocaleString != m_oldpreferredLocale)) {
		m_restartRequired = true;
	}

	// save file font encoding
	options->SetFileFontEncoding(m_fileEncoding->GetStringSelection());

	// Update the tags manager encoding
	TagsManagerST::Get()->SetEncoding(options->GetFileFontEncoding());

	if (oldIconSize != iconSize || oldUseSingleToolbar != m_useSingleToolbar->IsChecked()) {
		EditorConfigST::Get()->SaveLongValue(wxT("LoadSavedPrespective"), 0);
		//notify the user
		m_restartRequired = true;
	} else {
		EditorConfigST::Get()->SaveLongValue(wxT("LoadSavedPrespective"), 1);
	}
}

void EditorSettingsMiscPanel::OnClearUI(wxUpdateUIEvent& e)
{
	wxArrayString a1, a2;
	clMainFrame::Get()->GetMainBook()->GetRecentlyOpenedFiles(a1);
	ManagerST::Get()->GetRecentlyOpenedWorkspaces(a2);
	e.Enable(!a1.IsEmpty() && !a2.IsEmpty());
}

void EditorSettingsMiscPanel::OnEnableThemeUI(wxUpdateUIEvent& event)
{
#ifdef __WXMSW__
	int major, minor;
	wxGetOsVersion(&major, &minor);

	if(wxUxThemeEngine::GetIfActive() && major >= 6 /* Win 7 and up */) {
		event.Enable(true);
	} else {
		event.Enable(false);
	}
#else
	event.Enable(false);
#endif
}

void EditorSettingsMiscPanel::LocaleChkUpdateUI(wxUpdateUIEvent& event)
{
	event.Enable(m_AvailableLocales->GetCount() > 0);
}

void EditorSettingsMiscPanel::LocaleChoiceUpdateUI(wxUpdateUIEvent& event)
{
	event.Enable(m_SetLocale->IsChecked());
}

void EditorSettingsMiscPanel::LocaleStaticUpdateUI(wxUpdateUIEvent& event)
{
	event.Enable(m_SetLocale->IsChecked());
}

int EditorSettingsMiscPanel::FindAvailableLocales()
{
	wxArrayString canonicalNames;
	int select(wxNOT_FOUND), sysdefault_sel(wxNOT_FOUND);
	m_AvailableLocales->Clear();

	int system_lang = wxLocale::GetSystemLanguage();
	if (system_lang == wxLANGUAGE_UNKNOWN) {
		// Least-stupid fallback value
		system_lang = wxLANGUAGE_ENGLISH_US;
	}

	for (int n=0, lang=wxLANGUAGE_UNKNOWN+1; lang < wxLANGUAGE_USER_DEFINED; ++lang) {
		const wxLanguageInfo* info = wxLocale::GetLanguageInfo(lang);
		// Check there *is* a Canonical name, as empty strings return a valid locale :/
		if ((info && !info->CanonicalName.IsEmpty()) && wxLocale::IsAvailable(lang)) {

			// Check we haven't already seen this item: we may find the system default twice
			if (canonicalNames.Index(info->CanonicalName) == wxNOT_FOUND) {
				// Display the name as e.g. "en_GB: English (U.K.)"
				m_AvailableLocales->Append(info->CanonicalName + wxT(": ") + info->Description);
				canonicalNames.Add(info->CanonicalName);

				if (info->CanonicalName == m_oldpreferredLocale) {
					// Use this as the selection in the wxChoice
					select = n;
				}
				if (lang == system_lang) {
					// Use this as the selection if m_oldpreferredLocale isn't found
					sysdefault_sel = n;
				}
				++n;
			}
		}
	}

	return (select != wxNOT_FOUND) ? select:sysdefault_sel ;
}

void EditorSettingsMiscPanel::OnLogVerbosityChanged(wxCommandEvent& event)
{
	FileLogger::Get()->SetVerbosity(event.GetString());
	EditorConfigST::Get()->SaveLongValue(wxT("LogVerbosity"), FileLogger::GetVerbosityAsNumber(m_choice4->GetStringSelection()));
}

void EditorSettingsMiscPanel::OnShowLogFile(wxCommandEvent& event)
{
	wxUnusedVar(event);
	wxString logfile;
	logfile << wxStandardPaths::Get().GetUserDataDir()
			<< wxFileName::GetPathSeparator()
			<< wxT("codelite.log");
			
	clMainFrame::Get()->GetMainBook()->OpenFile(logfile);
}
