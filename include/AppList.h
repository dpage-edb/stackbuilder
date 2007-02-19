/////////////////////////////////////////////////////////////////////////////
// Name:        AppList.h
// Purpose:     Maintains the list of applications
// Author:      Dave Page
// Created:     2007-02-13
// RCS-ID:      $Id: AppList.h,v 1.1 2007/02/19 09:57:00 dpage Exp $
// Copyright:   (c) EnterpriseDB
// Licence:     BSD Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _APPLIST_H
#define _APPLIST_H

#include "StackBuilder.h"

// wxWindows headers
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/treectrl.h>
#include <wx/xml/xml.h>

// Application headers
#include "App.h"

WX_DECLARE_OBJARRAY(App, AppArray);

class AppList
{
public:
	AppList(const wxString &applicationListUrl) { m_applicationListUrl = applicationListUrl; };
	bool LoadAppList(ServerData *server);
	bool PopulateTreeCtrl();
    bool HaveDownloads();
	App *GetItem(unsigned int index) { return &m_apps[index]; };
	size_t Count() { return m_apps.Count(); };
	void SetTree(wxTreeCtrl *tree) { m_treectrl = tree; };

private:
	AppArray m_apps;
	wxString m_applicationListUrl;
	ServerData *m_server;
	wxTreeCtrl *m_treectrl;
};

#endif