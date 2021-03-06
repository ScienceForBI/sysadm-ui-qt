//===========================================
//  PC-BSD source code
//  Copyright (c) 2016, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _PCBSD_SYSADM_CLIENT_PAGE_WIDGET_UI_H
#define _PCBSD_SYSADM_CLIENT_PAGE_WIDGET_UI_H
#include "globals.h"
//===============================
// NOTES FOR CREATING SUBPAGES
//===============================
// 1) Subclass this PageWidget for any client page
// 2) Init any internal widgets/classes in the constructor
// 3) Setup any CORE connections in the "setupCore()" function
// 4) Start any CORE requests in the "startPage()" function
//===============================
class PageWidget : public QWidget{
	Q_OBJECT
public:
	sysadm_client *CORE;

	//Main constructor/destructor (create/destroy any interface items)
	PageWidget(QWidget *parent, sysadm_client *core) : QWidget(parent){
		CORE = core; //save the pointer to the core for access later
	}
	~PageWidget(){}
		
	//Initialize the CORE <-->Page connections
	virtual void setupCore(){}
		
	//Page embedded, go ahead and startup any core requests
	virtual void startPage(){}
		
	//Simple visual information about the page (icon, title, ID)
	// use the "windowTitle" and "windowIcon" properties on the QWidget for the display icon/title
	virtual QString pageID(){ return ""; } //ID is used to identify which type of page this is
	
public slots:
	//User requested to save any pending changes
	virtual void SaveSettings(){} 

signals:
	//emit this when the page has changes which are waiting to be saved
	void HasPendingChanges(); 
	//emit this when the page title changes (will updates main UI as needed)
	void ChangePageTitle(QString);

	//emit this when we need to change to another client/page (if needed - generally only used for the base/group pages)
	void ChangePage(QString); //ID of new page to open

};

#endif