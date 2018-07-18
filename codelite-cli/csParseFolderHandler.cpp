#include "csParseFolderHandler.h"
#include "csParsePHPFolderHandler.h"
#include <file_logger.h>

csParseFolderHandler::csParseFolderHandler(wxEvtHandler* sink)
    : csCommandHandlerBase(sink)
{
    m_parseHandlers.Register("parse-php-folder", csParsePHPFolderHandler::Ptr_t(new csParsePHPFolderHandler(sink)));
}

csParseFolderHandler::~csParseFolderHandler() {}

void csParseFolderHandler::DoProcessCommand(const JSONElement& options)
{
    CHECK_STR_OPTION("lang", m_language);
    CHECK_STR_OPTION("path", m_path);

    bool isDir = wxDirExists(m_path);
    wxString handlerName;
    handlerName << "parse-" << m_language << "-" << (isDir ? "folder" : "file");
    csCommandHandlerBase::Ptr_t handler = m_parseHandlers.FindHandler(handlerName);
    if(!handler) {
        clERROR() << "I have no handler for:" << handlerName;
        return;
    }
    clDEBUG() << "Using handler:" << handlerName;
    handler->DoProcessCommand(options);
}
