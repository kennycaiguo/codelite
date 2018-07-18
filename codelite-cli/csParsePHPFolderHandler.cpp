#include "csParsePHPFolderHandler.h"
#include "PHPLookupTable.h"
#include <wx/filename.h>

csParsePHPFolderHandler::csParsePHPFolderHandler(wxEvtHandler* sink)
    : csCommandHandlerBase(sink)
{
}

csParsePHPFolderHandler::~csParsePHPFolderHandler() {}

void csParsePHPFolderHandler::DoProcessCommand(const JSONElement& options)
{
    CHECK_STR_OPTION("path", m_folder);
    CHECK_STR_OPTION("mask", m_mask);
    PHPLookupTable lookup;
    wxFileName dbpath(m_folder, "phpsymbols.db");
    dbpath.AppendDir(".codelite");
    lookup.Open(dbpath);
    if(!lookup.IsOpened()) {
        clERROR() << "Could not open file:" << dbpath;
        return;
    }
    // Clear any content before we start the parsing
    lookup.ParseFolder(m_folder, m_mask, PHPLookupTable::kUpdateMode_Fast);
}
