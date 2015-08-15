#ifndef QREPORTPROPERTYPAGEFORMAT_H
#define QREPORTPROPERTYPAGEFORMAT_H

#include "qreportpropertypagebase.h"
#include "ui_qreportpropertypageformat.h"

class QReportPropertyPageFormat : public QReportPropertyPageBase, private Ui::QReportPropertyPageFormat
{
    Q_OBJECT

public:
    explicit QReportPropertyPageFormat(QWidget *parent = 0);

    void load();
    void save();

protected:
    void changeEvent(QEvent *e);

};

#endif // QREPORTPROPERTYPAGEFORMAT_H
