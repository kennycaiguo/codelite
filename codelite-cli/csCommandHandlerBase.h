#ifndef CSCOMMANDHANDLERBASE_H
#define CSCOMMANDHANDLERBASE_H

#include "file_logger.h"
#include "json_node.h"
#include <cl_command_event.h>
#include <wx/event.h>
#include <wx/sharedptr.h>
#include <wx/string.h>

wxDECLARE_EVENT(wxEVT_COMMAND_PROCESSED, clCommandEvent);

#define CHECK_STR_OPTION(str_option, sVal)                      \
    if(!options.hasNamedObject(str_option)) {                   \
        clERROR() << "Command is missing field:" << str_option; \
        NotifyCompletion();                                     \
        return;                                                 \
    }                                                           \
    sVal = options.namedObject(str_option).toString();

#define CHECK_INT_OPTION(str_option, iVal)                      \
    if(!options.hasNamedObject(str_option)) {                   \
        clERROR() << "Command is missing field:" << str_option; \
        NotifyCompletion();                                     \
        return;                                                 \
    }                                                           \
    iVal = options.namedObject(str_option).toInt();

#define CHECK_BOOL_OPTION(str_option, bVal)                     \
    if(!options.hasNamedObject(str_option)) {                   \
        clERROR() << "Command is missing field:" << str_option; \
        NotifyCompletion();                                     \
        return;                                                 \
    }                                                           \
    bVal = options.namedObject(str_option).toBool();

#define CHECK_ARRSTR_OPTION(str_option, arrVal)                 \
    if(!options.hasNamedObject(str_option)) {                   \
        clERROR() << "Command is missing field:" << str_option; \
        NotifyCompletion();                                     \
        return;                                                 \
    }                                                           \
    arrVal = options.namedObject(str_option).toArrayString();

class csCommandHandlerBase
{
protected:
    wxEvtHandler* m_sink;
    bool m_notifyOnExit;

public:
    typedef wxSharedPtr<csCommandHandlerBase> Ptr_t;

protected:
    void NotifyCompletion();
    void SetNotifyCompletion(bool b) { m_notifyOnExit = b; }
    
public:
    /**
     * @brief process a request from the command line and print the result to the stdout
     * @param the handler options
     */
    virtual void DoProcessCommand(const JSONElement& options) = 0;

public:
    csCommandHandlerBase(wxEvtHandler* sink);
    virtual ~csCommandHandlerBase();

    wxEvtHandler* GetSink() { return m_sink; }

    /**
     * @brief process a request from the command line and print the result to the stdout
     * @param the handler options
     */
    void Process(const JSONElement& options);
};

#endif // CSCOMMANDHANDLERBASE_H
