/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 3. May 11:45:22 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_COM;
    QAction *action;
    QAction *action_SAVE;
    QAction *action_LOAD;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(330, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(330, 300));
        MainWindow->setMaximumSize(QSize(330, 300));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        action_COM = new QAction(MainWindow);
        action_COM->setObjectName(QString::fromUtf8("action_COM"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_SAVE = new QAction(MainWindow);
        action_SAVE->setObjectName(QString::fromUtf8("action_SAVE"));
        action_LOAD = new QAction(MainWindow);
        action_LOAD->setObjectName(QString::fromUtf8("action_LOAD"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 61));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(120, 20, 81, 31));
        QPalette palette;
        QBrush brush(QColor(52, 212, 28, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton->setPalette(palette);
        pushButton->setCheckable(false);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 311, 161));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 20, 161, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 16));
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(130, 70, 160, 16));
        horizontalSlider->setMaximum(15);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 20));
        horizontalSlider_2 = new QSlider(groupBox_2);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(130, 120, 160, 16));
        horizontalSlider_2->setMinimum(200);
        horizontalSlider_2->setMaximum(1000);
        horizontalSlider_2->setSingleStep(10);
        horizontalSlider_2->setValue(500);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 101, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 330, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_COM);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\276.\321\202\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8));
        action_COM->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        action_SAVE->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        action_LOAD->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\202\320\276\320\272\320\276\320\273 \320\242\320\270\320\277 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\202\320\276\320\272\320\276\320\273 \320\242\320\270\320\277 2", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\277\320\276\321\201\321\213\320\273\320\272\320\270", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
