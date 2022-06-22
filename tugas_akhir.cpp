#include <iostream>             // Header Files
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <time.h>
using namespace std;

// Define Hero Structure
struct Hero {
    string name;
    int hp;
    int atk;
    int def;

    void basicAttack(int *pokemon_hp)
    {
        cout << "Basic Attack!" << endl;
        *pokemon_hp = *pokemon_hp - atk;
    }

    void FullPowerAttack(int *pokemon_hp)
    {
        cout << "Full Power Attack!" << endl;
        *pokemon_hp = *pokemon_hp - (atk * 2);
    }
};

// Define Pokemon Structure
struct Pokemon {
    string name;
    int hp;
    int atk;
    int def;
};

// Define Map Size
unsigned const mapX = 10;
unsigned const mapY = 10;

// Define Map
char map[mapY][mapX] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', 'M', 'M', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int main()
{
    // Variabel Declaration
    char movement = ' ';
    int playerY = 8;
    int playerX = 1;

    // Hero Object
    Hero player;
    player.name = "Player 1";
    player.hp = 100;
    player.atk = 10;
    player.def = 5;

    // Pokemon Object

    // Game Loop
    while (true)
    {
        // Clear Screen
        system("cls");

        // Print Map
        for (int y = 0; y < mapY; y++)
        {
            for (int x = 0; x < mapX; x++)
            {
                if (y == playerY && x == playerX)
                {
                    cout << '@' << " ";
                }
                else
                {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }

        // Input Movement
        char movement = getch();

        // Move Player
        if (movement == 'w' && playerY > 0)
        {
            playerY--;
        }
        else if (movement == 's' && playerY < mapY - 1)
        {
            playerY++;
        }
        else if (movement == 'a' && playerX > 0)
        {
            playerX--;
        }
        else if (movement == 'd' && playerX < mapX - 1)
        {
            playerX++;
        }
        else if (movement == 'e')
        {
            char input_keluar;
            cout << "Mau keluar?" << endl;
            cout << "input (y/n): ";
            input_keluar = getch();

            if (input_keluar == 'y')
            {
                break;
            }
            else
            {
                continue;
            }
        }

        // Check for Battle
        if (map[playerY][playerX] == 'M')
        {
            Pokemon pokemon_1;
            pokemon_1.name = "Pikachu";
            pokemon_1.hp = 100;
            pokemon_1.atk = 10;
            pokemon_1.def = 5;

            // Battle Loop
            while (true)
            {
                system("cls");
                char input_battle = ' ';
                cout << "Battle!" << endl;
                cout << "Player HP: " << player.hp << endl;
                cout << "Pokemon HP: " << pokemon_1.hp << endl;
                cout << "Klik tombol Q untuk basic attack!\n";
                cout << "Klik tombol E untuk Full Power attack!\n";
                cout << "Input : ";
                input_battle = getch();

                if (input_battle == 'q')
                {
                    player.basicAttack(&pokemon_1.hp);
                }

                if (input_battle == 'e')
                {
                    player.FullPowerAttack(&pokemon_1.hp);
                }

                if (pokemon_1.hp <= 0)
                {
                    map[playerY][playerX] = '.';
                    break;
                }
            }
        }
        else if (map[playerY][playerX] == '#')
        {
            Pokemon pokemon_1;
            pokemon_1.name = "Pikachu";
            pokemon_1.hp = 100;
            pokemon_1.atk = 10;
            pokemon_1.def = 5;

            Pokemon pokemon_2;
            pokemon_2.name = "Bulbasaur";
            pokemon_2.hp = 150;
            pokemon_2.atk = 10;
            pokemon_2.def = 5;

            srand(time(NULL));
            int random = rand() % 3; // 0 1 2

            while (true)
            {
                if (random == 0) // Ketemu pikachu
                {
                    system("cls");
                    char input_battle = ' ';
                    cout << "Battle!" << endl;
                    cout << "Ketemu " << pokemon_1.name << endl;
                    cout << "Player HP: " << player.hp << endl;
                    cout << "Pokemon HP: " << pokemon_1.hp << endl;
                    cout << "Klik tombol Q untuk basic attack!";
                    input_battle = getch();

                    if (input_battle == 'q')
                    {
                        player.basicAttack(&pokemon_1.hp);
                    }

                    if (pokemon_1.hp <= 0)
                    {
                        break;
                    }
                }
                else if (random == 1) // Ketemu bulbasaur
                {
                    system("cls");
                    char input_battle = ' ';
                    cout << "Battle!" << endl;
                    cout << "Ketemu " << pokemon_2.name << endl;
                    cout << "Player HP: " << player.hp << endl;
                    cout << "Pokemon HP: " << pokemon_2.hp << endl;
                    cout << "Klik tombol Q untuk basic attack!";
                    input_battle = getch();

                    if (input_battle == 'q')
                    {
                        player.basicAttack(&pokemon_2.hp);
                    }

                    if (pokemon_2.hp <= 0)
                    {
                        break;
                    }
                }
                else if (random == 2) // Gak ketemu apa2
                {
                    break;
                }
            }
        }
    }

    cout << "Terimakasih" << endl;
    getch();
    return 0;
}
