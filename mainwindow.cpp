#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

int bot_lvl;
int game_in_progress = 0;
int bot_num, player_num;
int cur_turn = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);
    ui->statusbar->showMessage("Choose bot lvl, write your number in case 'Write your number' and go play =)");

}

int MainWindow::bot_move(int lvl) {
    moove = 1;
    if (lvl == 3) {
        vector <int> posible_nums(0);
        for (int i = 1023; i <= 9876; ++i) {
            if (check_players_num(i)) {
                posible_nums.push_back(i);
            }
        }
        while (posible_nums.size() > 1) {
            if (posible_nums.size() == 2) {
                random_shuffle(posible_nums.begin(), posible_nums.end());
                nums[moove - 1] = posible_nums[0];
                if (posible_nums[0] == player_num) {
                    qDebug() << posible_nums[0] << moove;
                    return moove;
                } else {
                    ++moove;
                    nums[moove - 1] = posible_nums[1];
                    qDebug() << posible_nums[1] << moove;
                    return moove;
                }
            }
            random_shuffle(posible_nums.begin(), posible_nums.end());
            qDebug() << posible_nums[0];
            if (posible_nums[0] == player_num) {
                nums[moove - 1] = posible_nums[0];
                qDebug() << moove;
                return moove;
            }
            nums[moove - 1] = posible_nums[0];
            int bulls = bulls_cow_counter(player_num, posible_nums[0]).first;
            int cows = bulls_cow_counter(player_num, posible_nums[0]).second;
            int total = bulls + cows;
            vector <int> clear(0);
            int sigs[4];
            sigs[0] = posible_nums[0] / 1000;
            sigs[1] = posible_nums[0] / 100 % 10;
            sigs[2] = posible_nums[0] / 10 % 10;
            sigs[3] = posible_nums[0] % 10;
            qDebug() << posible_nums.size();
            clear.push_back(posible_nums[0]);
            for (size_t i = 1; i < posible_nums.size(); ++i) {
                int digs[4];
                digs[0] = posible_nums[i] / 1000;
                digs[1] = posible_nums[i] / 100 % 10;
                digs[2] = posible_nums[i] / 10 % 10;
                digs[3] = posible_nums[i] % 10;
                int position = (digs[0]==sigs[0]) + (digs[1]==sigs[1]) + (digs[2]==sigs[2]) + (digs[3]==sigs[3]);
                if (position == bulls) {
                    int tots = 0;
                    bool is[4] = { false, false, false, false };
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (is[j]) continue;
                            if (sigs[i] == digs[j]) {
                                tots++;
                                is[j] = true;
                                break;
                            }
                        }
                    }
                    if (tots == total) {
                        clear.push_back(posible_nums[i]);
                    }
                }
            }
            posible_nums.clear();
            posible_nums.resize(0);
            for (size_t i = 0; i < clear.size(); ++i) {
                posible_nums.push_back(clear[i]);
            }
            ++moove;
        }
        qDebug() << moove;
        --moove;
    } else if (lvl == 2) {
        vector <int> posible_nums(0);
        for (int i = 1023; i <= 9876; ++i) {
            if (check_players_num(i)) {
                posible_nums.push_back(i);
            }
        }
        while (posible_nums.size() > 1) {
            if (posible_nums.size() == 2) {
                random_shuffle(posible_nums.begin(), posible_nums.end());
                nums[moove - 1] = posible_nums[0];
                if (posible_nums[0] == player_num) {
                    qDebug() << posible_nums[0] << moove;
                    return moove;
                } else {
                    ++moove;
                    nums[moove - 1] = posible_nums[1];
                    qDebug() << posible_nums[1] << moove;
                    return moove;
                }
            }
            random_shuffle(posible_nums.begin(), posible_nums.end());
            qDebug() << posible_nums[0];
            if (posible_nums[0] == player_num) {
                nums[moove - 1] = posible_nums[0];
                qDebug() << moove;
                return moove;
            }
            nums[moove - 1] = posible_nums[0];
            int bulls = bulls_cow_counter(player_num, posible_nums[0]).first;
            int cows = bulls_cow_counter(player_num, posible_nums[0]).second;
            int total = bulls + cows;
            vector <int> clear(0);
            int sigs[4];
            sigs[0] = posible_nums[0] / 1000;
            sigs[1] = posible_nums[0] / 100 % 10;
            sigs[2] = posible_nums[0] / 10 % 10;
            sigs[3] = posible_nums[0] % 10;
            qDebug() << posible_nums.size();
            clear.push_back(posible_nums[0]);
            for (size_t i = 1; i < posible_nums.size(); ++i) {
                if (rand() % 10 == 0) {
                    clear.push_back(posible_nums[i]);
                    continue;
                }
                int digs[4];
                digs[0] = posible_nums[i] / 1000;
                digs[1] = posible_nums[i] / 100 % 10;
                digs[2] = posible_nums[i] / 10 % 10;
                digs[3] = posible_nums[i] % 10;
                int position = (digs[0]==sigs[0]) + (digs[1]==sigs[1]) + (digs[2]==sigs[2]) + (digs[3]==sigs[3]);
                if (position == bulls) {
                    int tots = 0;
                    bool is[4] = { false, false, false, false };
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (is[j]) continue;
                            if (sigs[i] == digs[j]) {
                                tots++;
                                is[j] = true;
                                break;
                            }
                        }
                    }
                    if (tots == total) {
                        clear.push_back(posible_nums[i]);
                    }
                }
            }
            posible_nums.clear();
            posible_nums.resize(0);
            for (size_t i = 0; i < clear.size(); ++i) {
                posible_nums.push_back(clear[i]);
            }
            ++moove;
        }
        qDebug() << moove;
        --moove;
    } else {
        vector <int> posible_nums(0);
        for (int i = 1023; i <= 9876; ++i) {
            if (check_players_num(i)) {
                posible_nums.push_back(i);
            }
        }
        while (posible_nums.size() > 1) {
            if (posible_nums.size() == 2) {
                random_shuffle(posible_nums.begin(), posible_nums.end());
                nums[moove - 1] = posible_nums[0];
                if (posible_nums[0] == player_num) {
                    qDebug() << posible_nums[0] << moove;
                    return moove;
                } else {
                    ++moove;
                    nums[moove - 1] = posible_nums[1];
                    qDebug() << posible_nums[1] << moove;
                    return moove;
                }
            }
            random_shuffle(posible_nums.begin(), posible_nums.end());
            qDebug() << posible_nums[0];
            if (posible_nums[0] == player_num) {
                nums[moove - 1] = posible_nums[0];
                qDebug() << moove;
                return moove;
            }
            nums[moove - 1] = posible_nums[0];
            int bulls = bulls_cow_counter(player_num, posible_nums[0]).first;
            int cows = bulls_cow_counter(player_num, posible_nums[0]).second;
            int total = bulls + cows;
            vector <int> clear(0);
            int sigs[4];
            sigs[0] = posible_nums[0] / 1000;
            sigs[1] = posible_nums[0] / 100 % 10;
            sigs[2] = posible_nums[0] / 10 % 10;
            sigs[3] = posible_nums[0] % 10;
            qDebug() << posible_nums.size();
            clear.push_back(posible_nums[0]);
            for (size_t i = 1; i < posible_nums.size(); ++i) {
                if (rand() % 6 == 0) {
                    clear.push_back(posible_nums[i]);
                    continue;
                }
                int digs[4];
                digs[0] = posible_nums[i] / 1000;
                digs[1] = posible_nums[i] / 100 % 10;
                digs[2] = posible_nums[i] / 10 % 10;
                digs[3] = posible_nums[i] % 10;
                int position = (digs[0]==sigs[0]) + (digs[1]==sigs[1]) + (digs[2]==sigs[2]) + (digs[3]==sigs[3]);
                if (position == bulls) {
                    int tots = 0;
                    bool is[4] = { false, false, false, false };
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (is[j]) continue;
                            if (sigs[i] == digs[j]) {
                                tots++;
                                is[j] = true;
                                break;
                            }
                        }
                    }
                    if (tots == total) {
                        clear.push_back(posible_nums[i]);
                    }
                }
            }
            posible_nums.clear();
            posible_nums.resize(0);
            for (size_t i = 0; i < clear.size(); ++i) {
                posible_nums.push_back(clear[i]);
            }
            ++moove;
        }
        qDebug() << moove;
        --moove;
    }
    return moove;
}

MainWindow::~MainWindow()
{
    delete ui;
}

pair <int, int> MainWindow::bulls_cow_counter(int input_num, int asked_num) {
    int a1, b1, c1, d1, a2, b2, c2, d2;
    d1 = input_num % 10;
    c1 = input_num / 10 % 10;
    b1 = input_num / 100 % 10;
    a1 = input_num / 1000;
    d2 = asked_num % 10;
    c2 = asked_num / 10 % 10;
    b2 = asked_num / 100 % 10;
    a2 = asked_num / 1000;
    int bulls = 0;
    int cows = 0;
    if (a1 == a2) {
        ++bulls;
    }
    if (b1 == b2) {
        ++bulls;
    }
    if (c1 == c2) {
        ++bulls;
    }
    if (d1 == d2) {
        ++bulls;
    }
    if (a1 == b2 || a1 == c2 || a1 == d2) {
        ++cows;
    }
    if (b1 == a2 || b1 == c2 || b1 == d2) {
        ++cows;
    }
    if (c1 == a2 || c1 == b2 || c1 == d2) {
        ++cows;
    }
    if (d1 == a2 || d1 == b2 || d1 == c2) {
        ++cows;
    }
    return make_pair(bulls, cows);
}

int MainWindow::create_bot_num() {
    int x = rand() % 9000 + 1000;
    int d = x % 10;
    int c = x / 10 % 10;
    int b = x / 100 % 10;
    int a = x / 1000;
    while (a == b || a == c || a == d || b == c || b == d || c == d) {
        x = rand() % 9000 + 1000;
        d = x % 10;
        c = x / 10 % 10;
        b = x / 100 % 10;
        a = x / 1000;
    }
    return x;
}

bool MainWindow::check_players_num(int x) {
    int a, b, c, d;
    d = x % 10;
    x /= 10;
    c = x % 10;
    x /= 10;
    b = x % 10;
    x /= 10;
    a = x;
    if (a == b || a == c || a == d || b == c || b == d || c == d) {
        return false;
    }
    return true;
}

void MainWindow::on_btn_Start_clicked()
{
    if (check_players_num(ui->spin_YourNum->value())) {
        bot_lvl = ui->spin_Botlvl->value();
        bot_num = create_bot_num();
        cur_turn = 1;
        ui->lbl_turnnum->setText("1");
        player_num = ui->spin_YourNum->value();
        game_in_progress = 1;
        ui->list_Scoreboard->clear();
        ui->list_Scoreboard->addItem("______Game started______");
        ui->statusbar->showMessage("Game has started! Write number to guess in case Input");
        for (int i = 0; i < 10; ++i) {
            nums[i] = 0;
        }
        if (bot_lvl == 3) {
            bot_move(3);
        } else if (bot_lvl == 2) {
            bot_move(2);
        } else {
            bot_move(1);
        }
        for (int h = 0; h < moove; ++h) {
            cout << nums[h] << endl;
        }
    } else {
        game_in_progress = 0;
        ui->statusbar->showMessage("Your num is incorrect, please choose num with different numerals and start");
    }
}

void MainWindow::on_btn_Input_clicked()
{
    if (game_in_progress) {

        int input_num = ui->spin_Input->value();
        if (!check_players_num(input_num)) {
            ui->statusbar->showMessage("Wrong number in case 'Input', pls write num with different numerals");
            return;
        }
        if (input_num == bot_num) {
            game_in_progress = 0;
            if (cur_turn < moove) {
                ui->statusbar->showMessage("YOU WON!!!");
                ui->list_Scoreboard->addItem("Player turn |  YOU WON!!!");
            } else {
                ui->statusbar->showMessage("IT`S DRAW!!!");
                ui->list_Scoreboard->addItem("     !!!DRAW!!!");
                string final = "Your num is: ";
                final += (char)('0' + (nums[cur_turn - 1] / 1000));
                final += (char)('0' + (nums[cur_turn - 1] / 100 % 10));
                final += (char)('0' + (nums[cur_turn - 1] / 10 % 10));
                final += (char)('0' + (nums[cur_turn - 1] % 10));
                ui->list_Scoreboard->addItem(QString::fromStdString(final));
            }
            game_in_progress = 0;
        } else {
            string num_checked = "";
            num_checked += (char)('0' + (input_num / 1000));
            num_checked += (char)('0' + (input_num / 100 % 10));
            num_checked += (char)('0' + (input_num / 10 % 10));
            num_checked += (char)('0' + (input_num % 10));
            int kolvo_bulls, kolvo_cows;
            kolvo_bulls = bulls_cow_counter(input_num, bot_num).first;
            kolvo_cows = bulls_cow_counter(input_num, bot_num).second;
            string bulls_cows = "";
            bulls_cows += "Bulls: ";
            bulls_cows += (char)('0' + kolvo_bulls);
            bulls_cows += "  Cows: ";
            bulls_cows += (char)('0' + kolvo_cows);
            string final = "Player turn |  ";
            final += num_checked;
            final += "   ";
            final += bulls_cows;
            ui->list_Scoreboard->addItem(QString::fromStdString(final));
            string turn_cur = "";
            int a = cur_turn;
            while (a != 0) {
                char c = a % 10 + '0';
                turn_cur += c;
                a /= 10;
            }
            reverse(turn_cur.begin(), turn_cur.end());
            ui->lbl_turnnum->setText(QString::fromStdString(turn_cur));
            if (cur_turn < moove) {
                string num_checked = "";
                num_checked += (char)('0' + (nums[cur_turn - 1] / 1000));
                num_checked += (char)('0' + (nums[cur_turn - 1] / 100 % 10));
                num_checked += (char)('0' + (nums[cur_turn - 1] / 10 % 10));
                num_checked += (char)('0' + (nums[cur_turn - 1] % 10));
                int kolvo_bulls, kolvo_cows;
                kolvo_bulls = bulls_cow_counter(nums[cur_turn - 1], player_num).first;
                kolvo_cows = bulls_cow_counter(nums[cur_turn - 1], player_num).second;
                string bulls_cows = "";
                bulls_cows += "Bulls: ";
                bulls_cows += (char)('0' + kolvo_bulls);
                bulls_cows += "  Cows: ";
                bulls_cows += (char)('0' + kolvo_cows);
                string final = "Bot turn |  ";
                final += num_checked;
                final += "   ";
                final += bulls_cows;
                ui->list_Scoreboard->addItem(QString::fromStdString(final));
            } else {
                ui->statusbar->showMessage("YOU LOSE");
                ui->list_Scoreboard->addItem("Player turn |  YOU LOSE!!!");
                string final = "Your num is: ";
                final += (char)('0' + (nums[cur_turn - 1] / 1000));
                final += (char)('0' + (nums[cur_turn - 1] / 100 % 10));
                final += (char)('0' + (nums[cur_turn - 1] / 10 % 10));
                final += (char)('0' + (nums[cur_turn - 1] % 10));
                ui->list_Scoreboard->addItem(QString::fromStdString(final));
                game_in_progress = 0;
            }
        }

        ++cur_turn;
    } else {
         ui->statusbar->showMessage("Game not started yet, press 'Start' to play");
    }
}
