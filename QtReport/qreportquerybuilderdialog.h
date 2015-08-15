/***************************************************************************
 *   QtReport                                                              *
 *   Qt Report Builder Soultion                                            *
 *                                                                         *
 *   Copyright (C) 2010 by Hamed Masafi                                    *
 *   Hamed.Masafi@GMail.COM                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef QREPORTQUERYBUILDERDIALOG_H
#define QREPORTQUERYBUILDERDIALOG_H

#include "ui_qreportquerybuilderdialog.h"

#include <QSqlDatabase>

class QReport;
class QReportQueryBuilderDialog : public QDialog, private Ui::QReportQueryBuilderDialog
{
    Q_OBJECT
    QString _tableName;

public:
    explicit QReportQueryBuilderDialog(QReport *report, QString connectionName, QWidget *parent = 0);

    QString tableName() const;
    QString query() const;

protected:
    void changeEvent(QEvent *e);

    QReport *_report;
    QTreeWidgetItem *nodeTableDB;
    QTreeWidgetItem *nodeViewDB;
    QSqlDatabase db;
private slots:
    void on_tablesTree_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
};

#endif // QREPORTQUERYBUILDERDIALOG_H
