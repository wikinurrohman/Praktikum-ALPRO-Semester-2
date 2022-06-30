 #include <conio.h>
#include <iostream>
#include "color.hpp"
using namespace std;

//DEFINISI 

// DEFINISI INPUT KEYBORD
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

//ISI PETA SECARA RANDOM
char map_randomizer() {
    char charReturnn;
    int random = rand() % 10;
    if (random == 1 || random == 10 || random == 6) {
        charReturnn = '=';
    } else if (random == 4 || random == 5 || random == 3) {
        charReturnn = 'X';
    } else if (random == 8) {
        charReturnn = 'T';
    } else if (random == 9) {
        charReturnn = 'Z';
    } else if (random == 7) {
        charReturnn = 'S';
    }
    return charReturnn;
}

// WAYANG STRUCT
struct wayang {
    string username;
    string wayang_name;
    int hp;
    int atk;
    int def;
    int gold;

    void basic_atk(int *hp_obj, int *def_obj) {
        int damage = (atk * 2) - *def_obj;
        cout << "Kamu Bertemu Musuh!\n"; 
        cout << "Kerusakan musuh " << dye::yellow(damage) << " menggunakan serangan standar!\n";
        *hp_obj -= damage;
    }

    void special_atk(int *hp_obj, int *def_obj) {
        int damage = (atk * 5) - *def_obj;
        cout << "Kamu Bertemu Musuh!\n";
        cout << "Kerusakan musuh " << dye::red(damage) << " menggunakan serangan sepesial!\n";
        *hp_obj -= damage;
    }
};

// MUSUH STRUCT
struct musuh {
    string musuh_name;
    int hp;
    int atk;
    int def;

    void musuh_atk(string name_obj ,int *hp_obj, int *def_obj) {
        int damage = (atk * 2) - *def_obj;
        cout << "\nKerusakan Wayang " << dye::yellow(damage) << " diserang oleh " << dye::white(name_obj) << "\n";
        *hp_obj -= damage;
    }
};

int main() {
    system("cls");
    int input_key;
    int musuh_atk_counter;
    int map_size = 16;
    int middle_map = map_size / 2;
    int player_x = middle_map;
    int player_y = map_size - 1;
    char map[map_size][map_size];   

    wayang player;
    musuh captainA;
    musuh avatar;
    musuh batman;

    cout << dye::red(R"(
         (                     )                (                                )             )          
   (     )\ )               ( /(       )        )\ )       (  (       (       ( /(   (      ( /(  (       
   )\   (()/(  (   (   (    )\())` )  /(    (  (()/( (     )\))(   '  )\      )\())  )\     )\()) )\ )    
((((_)(  /(_)) )\  )\  )\  ((_)\  ( )(_))   )\  /(_)))\   ((_)()\ )((((_)(   ((_)\((((_)(  ((_)\ (()/(    
 )\ _ )\(_))_ ((_)((_)((_)  _((_)(_(_()) _ ((_)(_)) ((_)  _(())\_)())\ _ )\ __ ((_))\ _ )\  _((_) /(_))_  
 (_)_\(_)|   \\ \ / / | __|| \| ||_   _|| | | || _ \| __| \ \((_)/ /(_)_\(_)\ \ / /(_)_\(_)| \| |(_)) __| 
  / _ \  | |) |\ V /  | _| | .` |  | |  | |_| ||   /| _|   \ \/\/ /  / _ \   \ V /  / _ \  | .` |  | (_ | 
 /_/ \_\ |___/  \_/   |___||_|\_|  |_|   \___/ |_|_\|___|   \_/\_/  /_/ \_\   |_|  /_/ \_\ |_|\_|   \___| )");
    cout << dye::grey("\nGame ini adalah sebuah petualangan pencarian musuh, musuh berada disekitar Anda maka hati hati setiap langkah Anda!\n");
    cout << "\n\n\t\t\t\t\tMasukan nama pemain Anda: ";
    cin >> player.username;

    cout << dye::aqua("Pilih jagoan wayang Anda: \n");
    cout << dye::aqua("1. Gatotkaca\n");
    cout << dye::aqua("2. Aswatama\n");
    cout << dye::aqua("3. Arjuna\n");
    cout << dye::aqua("4. Bima\n");
    cout << dye::aqua("5. Hanoman\n");
    select_wayang:
    cout << "Input: ";
    cin >> input_key;

    if (input_key == 1) {
        player.wayang_name = "Gatotkaca";
        player.hp = 200;
        player.atk = 10;
        player.def = 5;
    } else if (input_key == 2) {
        player.wayang_name = "Aswatama";
        player.hp = 230;
        player.atk = 20;
        player.def = 5;
    } else if (input_key == 3) {
        player.wayang_name = "Arjuna";
        player.hp = 400;
        player.atk = 20;
        player.def = 10;
    } else if (input_key == 4) {
        player.wayang_name = "Bima";
        player.hp = 280;
        player.atk = 20;
        player.def = 5;
    } else if (input_key == 5) {
        player.wayang_name = "Hanoman";
        player.hp = 250;
        player.atk = 15;
        player.def = 10;
    } else {
        cout << dye::red("Pilihan Anda salah!\n");
        goto select_wayang;
        return 0;
    }

    // PLAYER GOLD PRINT
    player.gold = 0;

    // PRINT MAP
                for (int y = 0; y < map_size; y++) {
                    for (int x = 0; x < map_size; x++) {
                        if (y == 0 && (x == middle_map - 1 || x == middle_map)) {
                            map[y][x] = 'D';
                        } else if (x == middle_map - 1 || x == middle_map) {
                            map[y][x] = '=';
                        } else if ((y == 0 || y == map_size - 1) || (x == 0 || x == map_size - 1)) {
                            map[y][x] = 'W';
                        }else {
                            map[y][x] = map_randomizer();
                        }
                    }
                }

    while (true) {
        system("cls");
    //player_move:
    player_move:
        // PRINT MAP
        cout << "\nWayang berada di x: " << player_x << ", di y: " << player_y << endl;
        for (int y = 0; y < map_size; y++) {
            for (int x = 0; x < map_size; x++) {
                if (y == player_y && x == player_x) {
                    cout << dye::purple("@") << " ";
                } else if (map[y][x] == '=') {
                    cout << dye::aqua("=") << " ";
                } else if (map[y][x] == 'X') {
                    cout << dye::white("X") << " ";
                } else if (map[y][x] == 'T') {
                    cout << dye::yellow("T") << " ";
                } else if (map[y][x] == 'Z') {
                    cout << dye::green("Z") << " ";
                } else if (map[y][x] == 'S') {
                    cout << dye::green("G") << " ";
                } else if (map[y][x] == 'W') {
                    cout << dye::red("W") << " ";
                } else {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }

        cout << "Tekan tombol panah untuk menggerakan wayang\n";
        cout << "Tekan tombol Enter untuk meliah status\n";
        cout << "Tekan tombol ESC untuk keluar dari game\n";
        cout << "Input: ";
        input_key = getch();

        // PLAYER MOVEMENT
        if (input_key == KEY_UP && player_y > 0) {
            if (map[player_y - 1][player_x] == 'W') {
                cout << "Tidak bisa bergerak ke atas!\n";
            } else {
                player_y--;
            }
        } else if (input_key == KEY_DOWN && player_y < map_size - 1) {
            if (map[player_y + 1][player_x] == 'W') {
                cout << "Tidak bisa bergerak ke bawah!\n";
            } else {
                player_y++;
            }
        } else if (input_key == KEY_LEFT && player_x > 0) {
            if (map[player_y][player_x - 1] == 'W') {
                cout << "Tidak bisa bergerak ke kiri!\n";
            } else {
                player_x--;
            }
        } else if (input_key == KEY_RIGHT && player_x < map_size - 1) {
            if (map[player_y][player_x + 1] == 'W') {
                cout << "Tidak bisa bergerak ke kanan!\n";
            } else {
                player_x++;
            }
        } else if (input_key == KEY_ENTER) {
            if (map[player_y][player_x] == 'D') {

                // PRINT MAP D
                cout << "\nWayang berada di x: " << player_x << ", di y: " << player_y << endl;
                for (int y = 0; y < map_size; y++) {
                    for (int x = 0; x < map_size; x++) {
                        if (y == player_y && x == player_x) {
                            cout << dye::purple("@") << " ";
                        } else if (map[y][x] == '=') {
                            cout << dye::grey("=") << " ";
                        } else if (map[y][x] == 'X') {
                            cout << dye::blue("X") << " ";
                        } else if (map[y][x] == 'T') {
                            cout << dye::purple("T") << " ";
                        } else if (map[y][x] == 'Z') {
                            cout << dye::yellow("H") << " ";
                        } else if (map[y][x] == 'S') {
                            cout << dye::green("S") << " ";
                        } else if (map[y][x] == 'W') {
                            cout << dye::red("Q") << " ";
                        } else {
                            cout << map[y][x] << " ";
                        }
                    }
                    cout << endl;
                }

                cout << "Tekan tombol panah untuk menggerakan wayang\n";
                cout << "Tekan tombol Enter untuk meliah status\n";
                cout << "Tekan tombol ESC untuk keluar dari game\n";
                cout << "Input: ";
                input_key = getch();

                // PLAYER MOVEMENT D
                if (input_key == KEY_UP && player_y > 0) {
                    if (map[player_y - 1][player_x] == 'W') {
                        cout << "Tidak bisa bergerak ke atas!\n";
                    } else {
                        player_y--;
                    }
                } else if (input_key == KEY_DOWN && player_y < map_size - 1) {
                    if (map[player_y + 1][player_x] == 'W') {
                        cout << "Tidak bisa bergerak ke bawah!\n";
                    } else {
                        player_y++;
                    }
                } else if (input_key == KEY_LEFT && player_x > 0) {
                    if (map[player_y][player_x - 1] == 'W') {
                        cout << "Tidak bisa bergerak ke kiri!\n";
                    } else {
                        player_x--;
                    }
                } else if (input_key == KEY_RIGHT && player_x < map_size - 1) {
                    if (map[player_y][player_x + 1] == 'W') {
                        cout << "Tidak bisa bergerak ke kanan!\n";
                    } else {
                        player_x++;
                    }
                }
            }
            
             else {
                cout << "\nStatus Wayang Anda:\n";
                cout << "Name   : " << player.username << endl;
                cout << "Wayang : " << player.wayang_name << endl;
                cout << "HP     : " << player.hp << endl;
                cout << "ATK    : " << player.atk << endl;
                cout << "DEF    : " << player.def << endl;
                cout << "Gold   : " << player.gold << endl;
                getch();
            }
        } else if (input_key == KEY_ESC) {
            cout << "Keluar dari game!!!" << endl;
            cout << "Terimakasih..." << endl;
            break;
        }

        // MONSTER FIGHT
        if (map[player_y][player_x] == 'O') {
            captainA.musuh_name = "Captain Amerika";
            captainA.hp = 150;
            captainA.atk = 10;
            captainA.def = 5;
            cout << "\n\nAnda bertemu dengan Captain Amerika!\n";
            while (true) {
                musuh_atk_counter = rand() % 2;
                cout << dye::red("\nCaptain Amerika HP  : ") << dye::red(captainA.hp) << endl;
                cout << dye::green("Wayang HP : ") << dye::green(player.hp) << endl;
                cout << "\nTekan ATAS untuk menyerang\n";
                cout << "Tekan BAWAH untuk menyerang mematikan\n";
            captainA_fight:
                cout << "Input: ";
                input_key = getch();

                system("CLS");

                if (input_key == KEY_UP && captainA.hp > 0) {
                    player.basic_atk(&captainA.hp, &captainA.def);
                } else if (input_key == KEY_DOWN && captainA.hp > 0) {
                    player.special_atk(&captainA.hp, &captainA.def);
                } else {
                    cout << "Input Gagal!\n";
                    goto captainA_fight;
                }

                if (musuh_atk_counter == 0) {
                    captainA.musuh_atk(captainA.musuh_name, &player.hp, &player.def);
                } else {
                    cout << "\nAnda menghindari serangan Captai Amerika!\n";
                }

                if (captainA.hp <= 0) {
                    cout << "\nAnda membunuh Captain Amerika!\n";
                    map[player_y][player_x] = '=';
                    getch();
                    goto player_move;
                } else if (player.hp <= 0) {
                    cout << "\nAnda mati!\n";
                    getch();
                    return 0;
                }
            }
        }else if (map[player_y][player_x] == 'X') {
            batman.musuh_name = "Batman";
            batman.hp = 175;
            batman.atk = 10;
            captainA.def = 5;
            cout << "\n\nAnda bertemu dengan Batman!\n";
            while (true) {
                musuh_atk_counter = rand() % 2;
                cout << dye::red("\nBatman HP  : ") << dye::red(batman.hp) << endl;
                cout << dye::green("Wayang HP : ") << dye::green(player.hp) << endl;
                cout << "\nTekan ATAS untuk menyerang\n";
                cout << "Tekan BAWAH untuk menyerang mematikan\n";
            batman_fight:
                cout << "Input: ";
                input_key = getch();

                system("CLS");

                if (input_key == KEY_UP && batman.hp > 0) {
                    player.basic_atk(&batman.hp, &batman.def);
                } else if (input_key == KEY_DOWN && batman.hp > 0) {
                    player.special_atk(&batman.hp, &batman.def);
                } else {
                    cout << "Input Gagal!\n";
                    goto batman_fight;
                }

                if (musuh_atk_counter == 0) {
                    batman.musuh_atk(batman.musuh_name, &player.hp, &player.def);
                } else {
                    cout << "\nAnda menghindari serangan Batman!\n";
                }

                if (batman.hp <= 0) {
                    cout << "\nAnda membunuh Batman!\n";
                    map[player_y][player_x] = '=';
                    getch();
                    goto player_move;
                } else if (player.hp <= 0) {
                    cout << "\nAnda mati!\n";
                    getch();
                    return 0;
                }
            }
        } else if (map[player_y][player_x] == 'G') {
            avatar.musuh_name = "Avatar";
            avatar.hp = 100;
            avatar.atk = 10;
            avatar.def = 5;
            cout << "\nAnda bertemu dengan Avatar!\n";
            while (true) {
                musuh_atk_counter = rand() % 2;
                cout << dye::red("\nAvatar HP : ") << dye::red(avatar.hp) << endl;
                cout << dye::green("Wayang HP   : ") << dye::green(player.hp) << endl;
                cout << "\nTekan ATAS untuk menyerang\n";
                cout << "Tekan BAWAH untuk menyerang mematikan\n";
            avatar_fight:
                cout << "Input: ";
                input_key = getch();

                system("CLS");

                if (input_key == KEY_UP && avatar.hp > 0) {
                    player.basic_atk(&avatar.hp, &avatar.def);
                } else if (input_key == KEY_DOWN && avatar.hp > 0) {
                    player.special_atk(&avatar.hp, &avatar.def);
                } else {
                    cout << "Input Gagal!\n";
                    goto avatar_fight;
                }

                if (musuh_atk_counter == 0) {
                    avatar.musuh_atk(avatar.musuh_name, &player.hp, &player.def);
                } else {
                    cout << "\nAnda menghindari serangan Avatar!\n";
                }

                if (avatar.hp <= 0) {
                    cout << "\nAnda membunuh Avatar!\n";
                    map[player_y][player_x] = '=';
                    getch();
                    break;
                } else if (player.hp <= 0) {
                    cout << "\nAnda mati!\n";
                    getch();
                    return 0;
                }
            }
        }

        // CHECK IF PLAYER IS ON A TREASURE
        if (map[player_y][player_x] == 'T') {
            cout << dye::green("\nAnda menemukan Sakti Milik!");
            player.gold = player.gold + rand() % 1000 + 1;
            map[player_y][player_x] = '=';
            getch();
            system("CLS");
            goto player_move;
        }
    }

    return 0;
} 