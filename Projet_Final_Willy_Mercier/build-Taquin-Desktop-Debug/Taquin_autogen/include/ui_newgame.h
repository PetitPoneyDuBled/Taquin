/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewGame
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewGame)
    {
        if (NewGame->objectName().isEmpty())
            NewGame->setObjectName(QString::fromUtf8("NewGame"));
        NewGame->resize(216, 210);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../annexes_projet_2023/240px-15-puzzle.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewGame->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(NewGame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(NewGame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(NewGame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(NewGame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(NewGame);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewGame, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewGame, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewGame);
    } // setupUi

    void retranslateUi(QDialog *NewGame)
    {
        NewGame->setWindowTitle(QCoreApplication::translate("NewGame", "Launch game", nullptr));
        label->setText(QCoreApplication::translate("NewGame", "Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewGame: public Ui_NewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
