//===========================================
//  PC-BSD source code
//  Copyright (c) 2016, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _PCBSD_SYSADM_CLIENT_CONNECTION_MANAGER_UI_H
#define _PCBSD_SYSADM_CLIENT_CONNECTION_MANAGER_UI_H

#include "globals.h"

namespace Ui{
	class C_Manager;
};

class C_Manager : public QMainWindow{
	Q_OBJECT
public:
	C_Manager();
	~C_Manager();

private:
	Ui::C_Manager *ui;
	QActionGroup *radio_acts;

	void LoadConnectionInfo();
	void SaveConnectionInfo();

	//Simplification functions for reading/writing tree widget paths
	QTreeWidgetItem* FindItemParent(QString path);
	void saveGroupItem(QTreeWidgetItem *group); 

private slots:
	//Page Changes
	void changePage(QAction*);

	//Connections Page
	void on_tree_conn_itemSelectionChanged();
	void on_push_conn_add_clicked();
	void on_push_conn_rem_clicked();
	void on_push_conn_export_clicked();
	void on_push_group_add_clicked();
	void on_push_group_rem_clicked();

	//SSL Page
	void on_push_ssl_create_clicked();
	void on_push_ssl_import_clicked();

signals:
	void SettingsChanged();

};

#endif