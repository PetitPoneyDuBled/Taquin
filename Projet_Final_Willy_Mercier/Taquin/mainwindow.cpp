#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QSpinBox>
#include <QLabel>
#include <QDebug>
#include "newgame.h"
#include "./ui_newgame.h"
#include <QGridLayout>
#include <QTableWidgetItem>
#include <random>
#include <algorithm>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::on_quit_changed);
    connect(ui->action_About_Qt, &QAction::triggered, this, &QApplication::aboutQt);
    connect(ui->action_About_Mystic_Square, &QAction::triggered, this, &MainWindow::on_action_About_Mystic_Square);
    connect(ui->actionCr_er_une_nouvelle_partie, &QAction::triggered, this, &MainWindow::on_Button_new_game_clicked);
    connect(ui->actionCharger_une_partie, &QAction::triggered, this, &MainWindow::on_Button_load_clicked);
    connect(ui->actionSave_game, &QAction::triggered, this, &MainWindow::on_Button_save_clicked);
    connect(ui->actionOriginal, &QAction::triggered, this, &MainWindow::on_actionOriginal_triggered);
    connect(ui->actionWood, &QAction::triggered, this, &MainWindow::on_actionWood_triggered);
    connect(ui->actionTree, &QAction::triggered, this, &MainWindow::on_actionTree_triggered);
    connect(ui->actionNetwork, &QAction::triggered, this, &MainWindow::on_actionNetwork_triggered);
    setupPuzzleGrid();
    gameWon = false;


}

void MainWindow::setupPuzzleGrid()
{
    QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");
    gridMsquare->setSpacing(1);
    int n = _nb_grid;

    int buttonSize = 100;
    int spacing = 15;

    for (int i = 0; i < n; i++) {
        gridMsquare->setRowMinimumHeight(i, buttonSize + spacing);
        for (int j = 0; j < n; j++) {
            gridMsquare->setColumnMinimumWidth(j, buttonSize + spacing);
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(buttonSize, buttonSize);
            button->setProperty("index", i * n + j );
            button->setText(QString::number(i * n + j + 1));
            button->setStyleSheet("background-color: #FFA500");
            QString buttonName = QString("button%1").arg(i * n + j);
            button->setObjectName(buttonName);
            gridMsquare->addWidget(button, i, j);

            if (i == n-1 && j == n-1) {
                button->setObjectName("invisibleButton");
                button->setVisible(false);
            }
        }
    }

    connectAllButtons();
}

void MainWindow::connectAllButtons()
{
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (int i = 0; i < buttons.size(); i++) {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(moveButton()));
    }
}

void MainWindow::on_quit_changed(){
    this->close();
}

void MainWindow::on_action_About_Mystic_Square() {
    QDialog* about_mystic_square = new QDialog(this);
    about_mystic_square->setWindowTitle(tr("About Mystic Square"));

    QPixmap* logoPicture = new QPixmap("/home/etud/Bureau/S6/interface/Projet_Final_Willy_Mercier/annexes_projet_2023/240px-15-puzzle.png");
    *logoPicture = logoPicture->scaled(50, 50);

    QLabel* logoLabel = new QLabel(about_mystic_square);
    logoLabel->setPixmap(*logoPicture);

    QLabel* textLabel = new QLabel(tr("This application was created by Willy MERCIER for the Qt project of L3 Informatique"), about_mystic_square);

    QHBoxLayout* hboxLayout = new QHBoxLayout();
    hboxLayout->addWidget(logoLabel);
    hboxLayout->addWidget(textLabel);

    QVBoxLayout* vboxLayout = new QVBoxLayout(about_mystic_square);
    vboxLayout->addLayout(hboxLayout);

    QPushButton* okButton = new QPushButton(tr("OK"), about_mystic_square);
    vboxLayout->addWidget(okButton, 0, Qt::AlignRight | Qt::AlignBottom);

    QObject::connect(okButton, &QPushButton::clicked, about_mystic_square, &QDialog::accept);

    about_mystic_square->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void splitImage(QImage image, int numSquares, QVector<QImage>& squares) {
    int squareSize = image.width() / numSquares;
    for (int row = 0; row < numSquares; row++) {
        for (int col = 0; col < numSquares; col++) {
            squares.append(image.copy(col * squareSize, row * squareSize, squareSize, squareSize));
        }
    }
}


void MainWindow::on_Button_new_game_clicked()
{
    NewGame n(this);

    int res = n.exec();

    if (res == QDialog::Accepted) {
        int value = n.getSpinBoxValue();
        set_Nbgrid(value);
    }



    QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");

    QLayoutItem *item;
    while ((item = gridMsquare->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    gridMsquare->setSpacing(1);
    int m = _nb_grid;

    int buttonSize = 100;

    QVector<int> randomSequence;
    for (int i = 0; i < m * m - 1; ++i) {
        randomSequence.append(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    do {
        std::shuffle(randomSequence.begin(), randomSequence.end(), g);
    } while (!checkSolvable(randomSequence, m));

    randomSequence.append(m * m - 1);

    for (int i = 0; i < m * m; ++i) {
        int row = i / m;
        int col = i % m;
        int num = randomSequence[i];

        QPushButton *button = new QPushButton(this);
        button->setFixedSize(buttonSize, buttonSize);
        button->setProperty("index", i);
        if (num != m * m - 1) {
            button->setText(QString::number(num + 1));
        }
        button->setStyleSheet("background-color: #FFA500");
        QString buttonName = QString("button%1").arg(i);
        button->setObjectName(buttonName);
        gridMsquare->addWidget(button, row, col);

        connect(button, SIGNAL(clicked()), this, SLOT(moveButton()));

        if (num == m * m - 1) {
            button->setObjectName("invisibleButton");
            button->setVisible(false);
        }
    }

    moveCount = 0;
    ui->label_2->setText(tr("Number of moves: ") + QString::number(moveCount));
    gameWon = false;

    if (!lastBackgroundImagePath.isEmpty()) {
        loadBackgroundImage(lastBackgroundImagePath);
    }


}

bool MainWindow::isPuzzleSolved() {
    QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");

    for (int i = 0; i < _nb_grid; i++) {
        for (int j = 0; j < _nb_grid; j++) {
            QPushButton *button = qobject_cast<QPushButton*>(gridMsquare->itemAtPosition(i, j)->widget());
            if (i == _nb_grid - 1 && j == _nb_grid - 1) {
                if (button->objectName() != "invisibleButton") {
                    return false;
                }
            } else {
                int expectedNum = i * _nb_grid + j;
                if (button->text().toInt() - 1 != expectedNum) {
                    return false;
                }
            }
        }
    }
    return true;
}


void MainWindow::moveButton()
{
    if (gameWon){
        return;
    }

    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    int clickedIndex = clickedButton->property("index").toInt();

    int invisibleIndex = findChild<QPushButton*>("invisibleButton")->property("index").toInt();

    int clickedRow = clickedIndex / _nb_grid;
    int clickedCol = clickedIndex % _nb_grid;
    int invisibleRow = invisibleIndex / _nb_grid;
    int invisibleCol = invisibleIndex % _nb_grid;

    if ((abs(clickedRow - invisibleRow) == 1 && clickedCol == invisibleCol) ||
        (abs(clickedCol - invisibleCol) == 1 && clickedRow == invisibleRow)) {

        QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");
        gridMsquare->removeWidget(clickedButton);
        gridMsquare->removeWidget(findChild<QPushButton*>("invisibleButton"));

        gridMsquare->addWidget(clickedButton, invisibleRow, invisibleCol);
        gridMsquare->addWidget(findChild<QPushButton*>("invisibleButton"), clickedRow, clickedCol);

        clickedButton->setProperty("index", invisibleIndex);
        findChild<QPushButton*>("invisibleButton")->setProperty("index", clickedIndex);

        moveCount++;
        ui->label_2->setText(tr("Number of moves: ") + QString::number(moveCount));


        if (isPuzzleSolved()) {
            QMessageBox::information(this, tr("Congratulations !"), tr("You finished the Mystic_Square in : ") + QString::number(moveCount) + tr(" moves !"));
            gameWon = true;
        }
    }
}


bool MainWindow::checkSolvable(const QVector<int>& sequence, int gridSize) {
    int inversions = 0;
    for (int i = 0; i < sequence.size(); i++) {
        for (int j = i + 1; j < sequence.size(); j++) {
            if (sequence[i] > sequence[j]) {
                inversions++;
            }
        }
    }

    if (gridSize % 2 == 1) {
        return inversions % 2 == 0;
    }
    else {
        int blankRow = (std::find(sequence.begin(), sequence.end(), gridSize * gridSize - 1) - sequence.begin()) / gridSize;
        return (blankRow + inversions) % 2 == 1;
    }
}

void MainWindow::on_Button_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Game"), "", tr("Save Files (*.save)"));

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::warning(this, tr("Error"), tr("Failed to open file for writing."));
                return;
            }

            QTextStream out(&file);

            out << _nb_grid << " " << moveCount << "\n";

            QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");

            for (int i = 0; i < _nb_grid; i++) {
                for (int j = 0; j < _nb_grid; j++) {
                    QWidget *widget = gridMsquare->itemAtPosition(i, j)->widget();
                    QString objName = widget->objectName();
                    int tileValue;

                    if (objName == "invisibleButton") {
                        tileValue = -1;
                    } else {
                        QPushButton *button = qobject_cast<QPushButton*>(widget);
                        tileValue = button->text().toInt() - 1;
                    }

                    out << tileValue << " ";
                }
                out << "\n";
            }
        }
}
void MainWindow::on_Button_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Game"), "", tr("Save Files (*.save)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);

            int gridSize;
            in >> gridSize >> moveCount;

            set_Nbgrid(gridSize);

            QGridLayout *gridMsquare = findChild<QGridLayout*>("gridLayout");
            QLayoutItem *item;
            while ((item = gridMsquare->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }

            for (int i = 0; i < gridSize; i++) {
                for (int j = 0; j < gridSize; j++) {
                    int tileValue;
                    in >> tileValue;

                    QPushButton *button = new QPushButton(this);
                    button->setFixedSize(100, 100);

                    if (tileValue == -1) {
                        button->setObjectName("invisibleButton");
                        button->setVisible(false);
                    } else {
                        button->setText(QString::number(tileValue + 1));
                        QString buttonName = QString("button%1").arg(i * gridSize + j);
                        button->setObjectName(buttonName);
                    }

                    button->setStyleSheet("background-color: #FFA500");
                    button->setProperty("index", i * gridSize + j);

                    gridMsquare->addWidget(button, i, j);
                    connect(button, SIGNAL(clicked()), this, SLOT(moveButton()));
                }
            }

            ui->label_2->setText(tr("Number of moves: ") + QString::number(moveCount));
        }
    }
    if (!lastBackgroundImagePath.isEmpty()) {
        loadBackgroundImage(lastBackgroundImagePath);
    }

}

void MainWindow::loadBackgroundImage(const QString &imagePath)
{
    QImage image(imagePath);
    int numSquares = _nb_grid;
    QVector<QImage> imageSquares;
    splitImage(image, numSquares, imageSquares);

    for (int i = 0; i < numSquares * numSquares; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("button%1").arg(i));
        if (button) {
            QIcon icon(QPixmap::fromImage(imageSquares[i]));
            button->setIcon(icon);
            button->setIconSize(button->size());
        }
    }
    lastBackgroundImagePath = imagePath;
}

void MainWindow::on_actionWood_triggered()
{
    QString imagePath = "../annexes_projet_2023/foret.jpg";
    loadBackgroundImage(imagePath);
}

void MainWindow::on_actionTree_triggered()
{
    QString imagePath = "../annexes_projet_2023/arbre-papillons.jpg";
    loadBackgroundImage(imagePath);
}

void MainWindow::on_actionNetwork_triggered()
{
    QString imagePath = "../annexes_projet_2023/reseau-informatique.jpeg";
    loadBackgroundImage(imagePath);
}

void MainWindow::on_actionOriginal_triggered()
{
    for (int i = 0; i < _nb_grid * _nb_grid; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("button%1").arg(i));
        if (button) {
            button->setIcon(QIcon()); // Supprime l'icône actuelle
            button->setText(QString::number(i + 1)); // Remet le texte du numéro
            button->setStyleSheet("background-color: #FFA500"); // Remet le style original
        }
    }
}
