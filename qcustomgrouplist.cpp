#include "qcustomgrouplist.h"

QCustomGroupList::QCustomGroupList(QWidget *parent) : QWidget(parent)
{
    m_headerModel = new QStandardItemModel();
    m_mainLayout = new QGridLayout();
    m_header = new QHeaderView(Qt::Horizontal, this);
    m_header->setModel(m_headerModel);
    m_header->setFixedHeight(30);
    m_header->setSectionsClickable(true);
    m_header->setSectionsMovable(true);
    m_header->show();
    m_mainLayout->addWidget(m_header);

    m_bodyFrame = new QFrame();
    m_mainLayout->addWidget(m_bodyFrame);

    this->setLayout(m_mainLayout);
}

void QCustomGroupList::setHeader(const QStringList &headers)
{
    for (const QString &_headerName : headers) {
        addHeaderItem(_headerName);
    }
}

void QCustomGroupList::addHeaderItem(const QString &headerName)
{
    int _nColumnCount = m_headerModel->columnCount();
    m_headerModel->setColumnCount(_nColumnCount + 1);
    m_headerModel->setHeaderData(_nColumnCount, Qt::Horizontal, headerName);
    for (int row = 0; row < m_headerModel->rowCount(); ++row) {
        m_headerModel->setItem(row, _nColumnCount, new QStandardItem(QString("Item %1").arg(row)));
    }
    emit sigAddedHeaderColumn();
}

