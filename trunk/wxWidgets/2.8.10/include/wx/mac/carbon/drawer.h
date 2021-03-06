/////////////////////////////////////////////////////////////////////////////
// Name:        wx/mac/carbon/drawer.h
// Purpose:     Drawer child window class.
//              Drawer windows appear under their parent window and
//              behave like a drawer, opening and closing to reveal
//              content that does not need to be visible at all times.
// Author:      Jason Bagley
// Modified by:
// Created:     2004-30-01
// RCS-ID:      $Id: drawer.h 42077 2006-10-17 14:44:52Z ABX $
// Copyright:   (c) Jason Bagley; Art & Logic, Inc.
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_DRAWERWINDOW_H_
#define _WX_DRAWERWINDOW_H_

#include "wx/toplevel.h"

//
// NB:  This is currently a private undocumented class -
// it is stable, but the API is not and will change in the
// near future
//

#if ( MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2 )

class WXDLLEXPORT wxDrawerWindow : public wxTopLevelWindow
{
    DECLARE_DYNAMIC_CLASS(wxDrawerWindow)

public:

    wxDrawerWindow();

    wxDrawerWindow(wxWindow* parent,
                   wxWindowID id,
                   const wxString& title,
                   wxSize size = wxDefaultSize,
                   wxDirection edge = wxLEFT,
                   const wxString& name = wxT("drawerwindow"))
    {
        this->Create(parent, id, title, size, edge, name);
    }

    virtual ~wxDrawerWindow();

    // Create a drawer window.
    // If parent is NULL, create as a tool window.
    // If parent is not NULL, then wxTopLevelWindow::Attach this window to parent.
    bool Create(wxWindow *parent,
     wxWindowID id,
     const wxString& title,
     wxSize size = wxDefaultSize,
     wxDirection edge = wxLEFT,
     const wxString& name = wxFrameNameStr);

    bool Open(bool show = true); // open or close the drawer, possibility for async param, i.e. animate
    bool Close() { return this->Open(false); }
    bool IsOpen() const;

    // Set the edge of the parent where the drawer attaches.
    bool SetPreferredEdge(wxDirection edge);
    wxDirection GetPreferredEdge() const;
    wxDirection GetCurrentEdge() const; // not necessarily the preferred, due to screen constraints
};

#endif // defined( __WXMAC__ ) && TARGET_API_MAC_OSX && ( MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2 )

#endif
    // _WX_DRAWERWINDOW_H_
