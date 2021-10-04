#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool check_players_num(int x);
    int create_bot_num();
    pair <int, int> bulls_cow_counter(int input_num, int asked_num);
    int nums[20];
    int bot_move(int lvl);
    int moove;

private slots:
    void on_btn_Start_clicked();

    void on_btn_Input_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
