#include "qcustomgrouplist.h"


QCollapseButton::QCollapseButton(QWidget *parent) : QWidget(parent)
{
    initialize(tr("New Group"));
}

QCollapseButton::QCollapseButton(QString name, QWidget *parent) : QWidget(parent)
{
    initialize(name);
}

void QCollapseButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_state = !m_state;
        emit sigClicked(m_state);
    }
}

void QCollapseButton::initialize(QString buttonText)
{
    m_state = false;
    m_mainLayout = new QHBoxLayout();

    m_collapeIcon = new QLabel();

    m_mainLayout->addWidget(m_collapeIcon);

    m_buttonText = new QLabel();
    m_buttonText->setText(buttonText);
    QString _buttonColor = "#1E3287";
    m_buttonText->setStyleSheet(QString("color: %d").arg(_buttonColor));
    m_mainLayout->addWidget(m_buttonText);

    m_line = new QFrame();
    m_line->setFrameShape(QFrame::HLine);
    m_line->setFrameShadow(QFrame::Sunken);
    QString _lineColor = "#B2C1E0";
    m_line->setStyleSheet(QString("QFrame {background-color: %1;}").arg(_lineColor));
    m_mainLayout->addWidget(m_line);
    setLayout(m_mainLayout);
}

void QCollapseButton::setText(const QString &text)
{
    m_buttonText->setText(text);
}

QCustomGroup::QCustomGroup(QWidget *parent) : QWidget(parent)
{
    m_toggleButton = new QCollapseButton(this);
}

void QCustomGroup::setGroupName(const QString &groupName)
{

}

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

