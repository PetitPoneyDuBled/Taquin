/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCr_er_une_nouvelle_partie;
    QAction *actionCharger_une_partie;
    QAction *actionSave_game;
    QAction *actionQuit;
    QAction *action_About_Qt;
    QAction *action_About_Mystic_Square;
    QAction *actionOriginal;
    QAction *actionWood;
    QAction *actionTree;
    QAction *actionNetwork;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Button_new_game;
    QPushButton *Button_load;
    QPushButton *Button_save;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menu0;
    QMenu *menuBackground;
    QMenu *menu1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../annexes_projet_2023/240px-15-puzzle.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionCr_er_une_nouvelle_partie = new QAction(MainWindow);
        actionCr_er_une_nouvelle_partie->setObjectName(QString::fromUtf8("actionCr_er_une_nouvelle_partie"));
        actionCharger_une_partie = new QAction(MainWindow);
        actionCharger_une_partie->setObjectName(QString::fromUtf8("actionCharger_une_partie"));
        actionSave_game = new QAction(MainWindow);
        actionSave_game->setObjectName(QString::fromUtf8("actionSave_game"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        action_About_Qt = new QAction(MainWindow);
        action_About_Qt->setObjectName(QString::fromUtf8("action_About_Qt"));
        action_About_Mystic_Square = new QAction(MainWindow);
        action_About_Mystic_Square->setObjectName(QString::fromUtf8("action_About_Mystic_Square"));
        actionOriginal = new QAction(MainWindow);
        actionOriginal->setObjectName(QString::fromUtf8("actionOriginal"));
        actionWood = new QAction(MainWindow);
        actionWood->setObjectName(QString::fromUtf8("actionWood"));
        actionTree = new QAction(MainWindow);
        actionTree->setObjectName(QString::fromUtf8("actionTree"));
        actionNetwork = new QAction(MainWindow);
        actionNetwork->setObjectName(QString::fromUtf8("actionNetwork"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Button_new_game = new QPushButton(centralwidget);
        Button_new_game->setObjectName(QString::fromUtf8("Button_new_game"));

        verticalLayout_2->addWidget(Button_new_game);

        Button_load = new QPushButton(centralwidget);
        Button_load->setObjectName(QString::fromUtf8("Button_load"));

        verticalLayout_2->addWidget(Button_load);

        Button_save = new QPushButton(centralwidget);
        Button_save->setObjectName(QString::fromUtf8("Button_save"));

        verticalLayout_2->addWidget(Button_save);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menu0 = new QMenu(menubar);
        menu0->setObjectName(QString::fromUtf8("menu0"));
        menuBackground = new QMenu(menubar);
        menuBackground->setObjectName(QString::fromUtf8("menuBackground"));
        menu1 = new QMenu(menubar);
        menu1->setObjectName(QString::fromUtf8("menu1"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu0->menuAction());
        menubar->addAction(menuBackground->menuAction());
        menubar->addAction(menu1->menuAction());
        menu0->addAction(actionCr_er_une_nouvelle_partie);
        menu0->addAction(actionCharger_une_partie);
        menu0->addAction(actionSave_game);
        menu0->addSeparator();
        menu0->addAction(actionQuit);
        menuBackground->addAction(actionOriginal);
        menuBackground->addAction(actionWood);
        menuBackground->addAction(actionTree);
        menuBackground->addAction(actionNetwork);
        menu1->addAction(action_About_Qt);
        menu1->addAction(action_About_Mystic_Square);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mystic Square", nullptr));
        actionCr_er_une_nouvelle_partie->setText(QCoreApplication::translate("MainWindow", "New game", nullptr));
#if QT_CONFIG(shortcut)
        actionCr_er_une_nouvelle_partie->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCharger_une_partie->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
#if QT_CONFIG(shortcut)
        actionCharger_une_partie->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_game->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_game->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_About_Qt->setText(QCoreApplication::translate("MainWindow", "\360\237\233\210 About Qt", nullptr));
        action_About_Mystic_Square->setText(QCoreApplication::translate("MainWindow", "\360\237\233\210 About Mystic Square", nullptr));
        actionOriginal->setText(QCoreApplication::translate("MainWindow", "Original", nullptr));
        actionWood->setText(QCoreApplication::translate("MainWindow", "Wood", nullptr));
        actionTree->setText(QCoreApplication::translate("MainWindow", "Tree", nullptr));
        actionNetwork->setText(QCoreApplication::translate("MainWindow", "Network", nullptr));
        Button_new_game->setText(QCoreApplication::translate("MainWindow", "New game", nullptr));
        Button_load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        Button_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Number of moves :", nullptr));
        menu0->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuBackground->setTitle(QCoreApplication::translate("MainWindow", "Background", nullptr));
        menu1->setTitle(QCoreApplication::translate("MainWindow", "\360\237\233\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
