//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "gitui.h"


// Declare the bitmap loading function
extern void wxCrafterpca4kKInitBitmapResources();

static bool bBitmapLoaded = false;


GitSettingsDlgBase::GitSettingsDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    wxFlexGridSizer* fgSizer1 = new wxFlexGridSizer(  0, 2, 0, 0);
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer1->AddGrowableCol(1);
    
    mainSizer->Add(fgSizer1, 0, wxALL|wxEXPAND, 5);
    
    m_staticText4 = new wxStaticText(this, wxID_ANY, _("Path to git executable:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    fgSizer1->Add(m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_pathGIT = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*"), wxDefaultPosition, wxSize(-1, -1), wxFLP_DEFAULT_STYLE);
    
    fgSizer1->Add(m_pathGIT, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText5 = new wxStaticText(this, wxID_ANY, _("Path to gitk executable:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    fgSizer1->Add(m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_pathGITK = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*"), wxDefaultPosition, wxSize(-1, -1), wxFLP_DEFAULT_STYLE);
    
    fgSizer1->Add(m_pathGITK, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    mainSizer->Add(0, 0, 1, wxEXPAND, 5);
    
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLI_HORIZONTAL);
    
    mainSizer->Add(m_staticline1, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizer3 = new wxBoxSizer(wxHORIZONTAL);
    
    mainSizer->Add(bSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_buttonOk = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOk->SetDefault();
    
    bSizer3->Add(m_buttonOk, 0, wxALL, 5);
    
    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer3->Add(m_buttonCancel, 0, wxALL, 5);
    
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
}

GitSettingsDlgBase::~GitSettingsDlgBase()
{
}

GitCommitDlgBase::GitCommitDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer4 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer4);
    
    m_splitter2 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxSP_LIVE_UPDATE|wxSP_3DSASH);
    m_splitter2->SetSashGravity(0.500000);
    m_splitter2->SetMinimumPaneSize(0);
    
    bSizer4->Add(m_splitter2, 1, wxALL|wxEXPAND, 5);
    
    m_panel3 = new wxPanel(m_splitter2, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* bSizer12 = new wxBoxSizer(wxVERTICAL);
    m_panel3->SetSizer(bSizer12);
    
    m_splitter1 = new wxSplitterWindow(m_panel3, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxSP_LIVE_UPDATE|wxSP_3DSASH);
    m_splitter1->SetSashGravity(0.500000);
    m_splitter1->SetMinimumPaneSize(0);
    
    bSizer12->Add(m_splitter1, 1, wxEXPAND, 5);
    
    m_panel1 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* bSizer11 = new wxBoxSizer(wxVERTICAL);
    m_panel1->SetSizer(bSizer11);
    
    m_staticText6 = new wxStaticText(m_panel1, wxID_ANY, _("Modified paths:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer11->Add(m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    wxArrayString m_listBoxArr;
    m_listBox = new wxCheckListBox(m_panel1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_listBoxArr, wxLB_SINGLE);
    
    bSizer11->Add(m_listBox, 1, wxALL|wxEXPAND, 5);
    
    m_panel2 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    m_splitter1->SplitVertically(m_panel1, m_panel2, 0);
    
    wxBoxSizer* bSizer9 = new wxBoxSizer(wxVERTICAL);
    m_panel2->SetSizer(bSizer9);
    
    m_staticText7 = new wxStaticText(m_panel2, wxID_ANY, _("Diff:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer9->Add(m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_editor = new GitCommitEditor( m_panel2 );
    bSizer9->Add(m_editor, 1, wxALL|wxEXPAND, 5);
    
    m_panel4 = new wxPanel(m_splitter2, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    m_splitter2->SplitHorizontally(m_panel3, m_panel4, 0);
    
    wxBoxSizer* bSizer13 = new wxBoxSizer(wxVERTICAL);
    m_panel4->SetSizer(bSizer13);
    
    m_staticText8 = new wxStaticText(m_panel4, wxID_ANY, _("Commit message:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer13->Add(m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_commitMessage = new wxTextCtrl(m_panel4, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), wxTE_WORDWRAP|wxTE_RICH2|wxTE_MULTILINE);
    wxFont m_commitMessageFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans"));
    m_commitMessage->SetFont(m_commitMessageFont);
    
    bSizer13->Add(m_commitMessage, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizer5 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer4->Add(bSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button5 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button5->SetDefault();
    
    bSizer5->Add(m_button5, 0, wxALL, 5);
    
    m_button6 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer5->Add(m_button6, 0, wxALL, 5);
    
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_listBox->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitCommitDlgBase::OnChangeFile), NULL, this);
    m_button5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GitCommitDlgBase::OnCommitOK), NULL, this);
    
}

GitCommitDlgBase::~GitCommitDlgBase()
{
    m_listBox->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitCommitDlgBase::OnChangeFile), NULL, this);
    m_button5->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GitCommitDlgBase::OnCommitOK), NULL, this);
    
}

GitCommitListDlgBase::GitCommitListDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer17 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer17);
    
    wxStaticBoxSizer* sbSizer1 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Commit List")), wxVERTICAL);
    
    bSizer17->Add(sbSizer1, 1, wxALL|wxEXPAND, 5);
    
    m_commitListBox = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLC_VRULES|wxLC_HRULES|wxLC_REPORT);
    
    sbSizer1->Add(m_commitListBox, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizer18 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer17->Add(bSizer18, 2, wxEXPAND, 5);
    
    wxStaticBoxSizer* sbSizer3 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Modified files")), wxVERTICAL);
    
    bSizer18->Add(sbSizer3, 1, wxALL|wxEXPAND, 5);
    
    wxArrayString m_fileListBoxArr;
    m_fileListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_fileListBoxArr, 0);
    
    sbSizer3->Add(m_fileListBox, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5);
    
    wxStaticBoxSizer* sbSizer5 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Diff")), wxVERTICAL);
    
    bSizer18->Add(sbSizer5, 2, wxALL|wxEXPAND, 5);
    
    m_editor = new GitCommitEditor( this );
    sbSizer5->Add(m_editor, 1, wxALL|wxEXPAND, 5);
    
    wxStaticBoxSizer* sbSizer2 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Commit Message")), wxVERTICAL);
    
    bSizer17->Add(sbSizer2, 1, wxALL|wxEXPAND, 5);
    
    m_commitMessage = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), wxTE_RICH2|wxTE_MULTILINE);
    
    sbSizer2->Add(m_commitMessage, 1, wxALL|wxEXPAND, 5);
    
    m_staticline4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLI_HORIZONTAL);
    
    bSizer17->Add(m_staticline4, 0, wxALL|wxEXPAND, 5);
    
    m_sdbSizer1 = new wxStdDialogButtonSizer();
    
    bSizer17->Add(m_sdbSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button136 = new wxButton(this, wxID_OK, _(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button136->SetDefault();
    m_sdbSizer1->AddButton(m_button136);
    m_sdbSizer1->Realize();
    
    
    SetSizeHints(879,600);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_commitListBox->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(GitCommitListDlgBase::OnChangeCommit), NULL, this);
    m_fileListBox->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitCommitListDlgBase::OnChangeFile), NULL, this);
    
}

GitCommitListDlgBase::~GitCommitListDlgBase()
{
    m_commitListBox->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(GitCommitListDlgBase::OnChangeCommit), NULL, this);
    m_fileListBox->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitCommitListDlgBase::OnChangeFile), NULL, this);
    
}

GitDiffDlgBase::GitDiffDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer17 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer17);
    
    wxBoxSizer* bSizer18 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer17->Add(bSizer18, 2, wxALL|wxEXPAND, 5);
    
    wxStaticBoxSizer* sbSizer3 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Modified files")), wxVERTICAL);
    
    bSizer18->Add(sbSizer3, 1, wxRIGHT|wxEXPAND, 5);
    
    wxArrayString m_fileListBoxArr;
    m_fileListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_fileListBoxArr, 0);
    
    sbSizer3->Add(m_fileListBox, 1, wxALL|wxEXPAND, 5);
    
    wxStaticBoxSizer* sbSizer5 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Diff")), wxVERTICAL);
    
    bSizer18->Add(sbSizer5, 2, wxEXPAND, 5);
    
    m_editor = new GitCommitEditor( this );
    sbSizer5->Add(m_editor, 1, wxALL|wxEXPAND, 5);
    
    m_sdbSizer1 = new wxStdDialogButtonSizer();
    
    bSizer17->Add(m_sdbSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button145 = new wxButton(this, wxID_OK, _(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button145->SetDefault();
    m_sdbSizer1->AddButton(m_button145);
    m_sdbSizer1->Realize();
    
    
    SetSizeHints(879,600);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_fileListBox->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitDiffDlgBase::OnChangeFile), NULL, this);
    
}

GitDiffDlgBase::~GitDiffDlgBase()
{
    m_fileListBox->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GitDiffDlgBase::OnChangeFile), NULL, this);
    
}

GitImages::GitImages()
    : wxImageList(16, 16, true)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    wxBitmap bmp;
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitCommitLocal"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitCommitLocal"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitArrowUp"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitArrowUp"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitSwitchLocalBranch"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitSwitchLocalBranch"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitNewBranch"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitNewBranch"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitDiffs"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitDiffs"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitCommitedFiles"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitCommitedFiles"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitModifiedFiles"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitModifiedFiles"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitPull"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitPull"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitPush"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitPush"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitReset"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitReset"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitTrash"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitTrash"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitRefresh"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitRefresh"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitStart"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitStart"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitFileAdd"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitFileAdd"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitClone"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitClone"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("git"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("git"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitPath"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitPath"), bmp ) );
    
    bmp = wxXmlResource::Get()->LoadBitmap(wxT("gitSettings"));
    this->Add( bmp );
    m_bitmaps.insert( std::make_pair(wxT("gitSettings"), bmp ) );
    
    
}

GitImages::~GitImages()
{
}

gitCloneDlgBaseClass::gitCloneDlgBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer17 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer17);
    
    wxFlexGridSizer* flexGridSizer21 = new wxFlexGridSizer(  0, 2, 0, 0);
    flexGridSizer21->SetFlexibleDirection( wxBOTH );
    flexGridSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer21->AddGrowableCol(1);
    
    boxSizer17->Add(flexGridSizer21, 1, wxALL|wxEXPAND, 5);
    
    m_staticText22 = new wxStaticText(this, wxID_ANY, _("Clone URL:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer21->Add(m_staticText22, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlURL = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlURL->SetToolTip(_("git URL to clone"));
    
    flexGridSizer21->Add(m_textCtrlURL, 0, wxALL|wxEXPAND, 5);
    
    m_staticText24 = new wxStaticText(this, wxID_ANY, _("Target Directory:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer21->Add(m_staticText24, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_dirPickerTargetDir = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST);
    m_dirPickerTargetDir->SetToolTip(_("Clone the sources into this target directory"));
    
    flexGridSizer21->Add(m_dirPickerTargetDir, 0, wxALL|wxEXPAND, 5);
    
    flexGridSizer21->Add(0, 0, 0, wxALL, 5);
    
    m_checkBoxUseLogin = new wxCheckBox(this, wxID_ANY, _("Use login credentials:"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxUseLogin->SetValue(false);
    
    flexGridSizer21->Add(m_checkBoxUseLogin, 0, wxALL|wxALIGN_LEFT, 5);
    
    m_staticText28 = new wxStaticText(this, wxID_ANY, _("Username:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer21->Add(m_staticText28, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlUsername = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer21->Add(m_textCtrlUsername, 0, wxALL|wxEXPAND, 5);
    
    m_staticText30 = new wxStaticText(this, wxID_ANY, _("Password:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer21->Add(m_staticText30, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlPassword = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PASSWORD);
    
    flexGridSizer21->Add(m_textCtrlPassword, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer18 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer17->Add(boxSizer18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_buttonOK = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonOK->SetDefault();
    
    boxSizer18->Add(m_buttonOK, 0, wxALL, 5);
    
    m_button20 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer18->Add(m_button20, 0, wxALL, 5);
    
    
    SetSizeHints(500,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_staticText28->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_textCtrlUsername->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_staticText30->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_textCtrlPassword->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnOKUI), NULL, this);
    
}

gitCloneDlgBaseClass::~gitCloneDlgBaseClass()
{
    m_staticText28->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_textCtrlUsername->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_staticText30->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_textCtrlPassword->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnUseCredentialsUI), NULL, this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(gitCloneDlgBaseClass::OnOKUI), NULL, this);
    
}

GitConsoleBase::GitConsoleBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterpca4kKInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer36 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer36);
    
    m_auibar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_DEFAULT_STYLE);
    m_auibar->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer36->Add(m_auibar, 0, wxEXPAND, 5);
    
    m_auibar->AddTool(wxID_CLEAR, _("Clear Log"), wxXmlResource::Get()->LoadBitmap(wxT("clear")), wxNullBitmap, wxITEM_NORMAL, _("Clear Log"), _("Clear Log"), NULL);
    
    m_auibar->AddTool(wxID_ABORT, _("m_toolKill"), wxXmlResource::Get()->LoadBitmap(wxT("stop")), wxNullBitmap, wxITEM_NORMAL, _("Terminate git process"), _("Terminate git process"), NULL);
    m_auibar->Realize();
    
    wxBoxSizer* boxSizer45 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer36->Add(boxSizer45, 1, wxALL|wxEXPAND, 5);
    
    m_stc = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_stcFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_stc->SetFont(m_stcFont);
    // Configure the fold margin
    m_stc->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stc->SetMarginSensitive(4, true);
    m_stc->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stc->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stc->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stc->SetMarginWidth(2, 0);
    m_stc->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stc->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stc->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stc->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stc->SetMarginMask(3, 0);
    m_stc->SetMarginWidth(3,0);
    // Select the lexer
    m_stc->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stc->StyleClearAll();
    for(int i=0; i<wxSTC_STYLE_MAX; ++i) {
        m_stc->StyleSetFont(i, m_stcFont);
    }
    m_stc->SetWrapMode(0);
    m_stc->SetIndentationGuides(0);
    m_stc->SetKeyWords(0, wxT(""));
    m_stc->SetKeyWords(1, wxT(""));
    m_stc->SetKeyWords(2, wxT(""));
    m_stc->SetKeyWords(3, wxT(""));
    m_stc->SetKeyWords(4, wxT(""));
    
    boxSizer45->Add(m_stc, 1, wxEXPAND, 5);
    
    m_checkBoxVerbose = new wxCheckBox(this, wxID_ANY, _("Verbose logging"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxVerbose->SetValue(false);
    
    boxSizer36->Add(m_checkBoxVerbose, 0, wxALL, 5);
    
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(GitConsoleBase::OnClearGitLog), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GitConsoleBase::OnClearGitLogUI), NULL, this);
    this->Connect(wxID_ABORT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(GitConsoleBase::OnStopGitProcess), NULL, this);
    this->Connect(wxID_ABORT, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GitConsoleBase::OnStopGitProcessUI), NULL, this);
    
}

GitConsoleBase::~GitConsoleBase()
{
    this->Disconnect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(GitConsoleBase::OnClearGitLog), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GitConsoleBase::OnClearGitLogUI), NULL, this);
    this->Disconnect(wxID_ABORT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(GitConsoleBase::OnStopGitProcess), NULL, this);
    this->Disconnect(wxID_ABORT, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(GitConsoleBase::OnStopGitProcessUI), NULL, this);
    
}
