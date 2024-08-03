#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <string>
#include <windows.h>
#include "TicTacToe.h"
#include "MainMenu.h"

using namespace std;

void setTConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // Define border characters
    const char* horizontalBorder = "+-----------------------------------------+";
    const char* verticalBorder = "|";

    char Ttt[3][3]{
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    string Plyr1;
    string Plyr2;
    string history = "";

    int selected = 1;
    bool running = true;

    while (running) {
        Menu* mainmenu = new Menu(); 
        mainmenu->MainMenu(selected);

        int key = _getch();

        switch (key) {
            case 72: // Up arrow
                if (selected > 1) selected--;
                break;
            case 80: // Down arrow
                if (selected < 3) selected++;
                break;
            case 13: // Enter
                {
                    switch (selected) {
                        case 1:
                        {
                            // Print the top border
                            setTConsoleColor(6);
                            system("cls");
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "                Tic-Tac-Toe              " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            // Player informationverticalBorder
                            cout << "\t\t\t\t" << verticalBorder << " Enter player 1's name: ";
                            setTConsoleColor(11);
                            cin >> Plyr1;
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << " Enter player 2's name: "; 
                            setTConsoleColor(11);
                            cin >> Plyr2;
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            system("cls");
                            // Input Location format
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            setTConsoleColor(11);
                            cout << "\t\t\t\t" << "Welcome to the game " << Plyr1 << " and " << Plyr2 << "." << endl;
                            cout << "\t\t\t\t" << "Please following the rule of TicTacToe board below!" << endl;
                            cout << "\t\t\t\t" << "Enter the number from 1 to 9 to play  " << endl;
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      1      |      2      |      3      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      4      |      5      |      6      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      7      |      8      |      9      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << horizontalBorder << endl;

                            TicTacToe* tictactoe = new TicTacToe();
                            // Input
                            string winner = tictactoe->PlayerInput(Ttt, &Plyr1, &Plyr2);
                            // Update history
                            history += "\t\t\t\tThe last winner is: " + winner + "\n";
                            // Output
                            tictactoe->Display(&winner, Plyr1, Plyr2);
                        }
                            break;
                        case 2:
                        {
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << "History of Winner: \n" << history;
                            cout << "\t\t\t\t" << "Press any key to return to menu...\n";
                            _getch(); // Wait for a key press
                        }
                            break;
                        case 3:
                            cout << "\t\t\t\t" << "\nYou are exiting the game...\n";
                            exit(0);
                            break;
                    }
                    break;
                }
        }
    }
    return 0;
}