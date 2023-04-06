#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_Nbgrid(int a){
        _nb_grid = a;
    }

    int getNbgrid() const {
        return _nb_grid;
    }

private slots:
    void on_quit_changed();

    void on_action_About_Mystic_Square();

    void on_Button_new_game_clicked();

    void moveButton();

    bool isPuzzleSolved();

    bool checkSolvable(const QVector<int>& sequence, int gridSize);

    void connectAllButtons();

    void setupPuzzleGrid();

    void on_Button_save_clicked();

    void on_Button_load_clicked();

    void loadBackgroundImage(const QString &imagePath);

    void on_actionWood_triggered();

    void on_actionOriginal_triggered();

    void on_actionTree_triggered();

    void on_actionNetwork_triggered();

private:

    int _nb_grid = 3;

    int moveCount = 0;

    bool gameWon;

    QString lastBackgroundImagePath;

private:
    Ui::MainWindow *ui;
};
#endif
