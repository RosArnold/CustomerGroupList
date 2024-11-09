#ifndef QCUSTOMGROUPLIST_H
#define QCUSTOMGROUPLIST_H

#include <QWidget>
#include <QHeaderView>
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>

class QCustomGroupList : public QWidget
{
    Q_OBJECT
public:
    explicit QCustomGroupList(QWidget *parent = nullptr);
    QHeaderView* header() {
        return m_header;
    }
    void setHeader(const QStringList &headers);
    void addHeaderItem(const QString &headerName);
private:
    QGridLayout         *m_mainLayout;
    QHeaderView         *m_header;
    QStandardItemModel  *m_headerModel;
    QFrame              *m_bodyFrame;

signals:
    void sigAddedHeaderColumn();
};

#endif // QCUSTOMGROUPLIST_H
