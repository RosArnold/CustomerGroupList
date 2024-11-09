#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_groupWidget = new QCustomGroupList(this);
    m_groupWidget->setHeader({tr("Name"), tr("Description"),tr("Command Line"), tr("Publisher"), tr("CPU"), tr("Virus Total")});

    setCentralWidget(m_groupWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

