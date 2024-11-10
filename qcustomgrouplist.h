#ifndef QCUSTOMGROUPLIST_H
#define QCUSTOMGROUPLIST_H

#include <QWidget>
#include <QHeaderView>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QPropertyAnimation>

class QCollapseButton : public QWidget {
    Q_OBJECT
public:
    explicit QCollapseButton(QWidget *parent = nullptr);
    QCollapseButton(QString name, QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *);


private:
    bool             m_state;
    QHBoxLayout     *m_mainLayout;
    QLabel          *m_collapeIcon;
    QLabel          *m_buttonText;
    QFrame          *m_line;

    void initialize(QString buttonText);
    void setText(const QString &text);
signals:
    void sigClicked(bool);
};

class QCustomGroup : public QWidget {
    Q_OBJECT
public:
    explicit QCustomGroup(QWidget *parent = nullptr);

    void setGroupName(const QString &groupName);

private:
    QCollapseButton     *m_toggleButton;
    QVBoxLayout         *m_mainLayout;

    
};

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
