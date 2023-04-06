#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

int NewGame::getSpinBoxValue() const
{
    return ui->spinBox->value();
}

NewGame::~NewGame()
{
    delete ui;
}
