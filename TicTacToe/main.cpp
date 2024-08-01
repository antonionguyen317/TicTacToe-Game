#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <string>
#include <windows.h>
#include "TicTacToe.h"
#include "Menu.h"

using namespace std;

void setTConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    
    // Define border characters
    const char* horizontalBorder = "+----------------------------------------+";
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
        Menu(selected);

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
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "                Tic-Tac-Toe              " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            // Player information
                            cout << "\t\t\t\t" << verticalBorder << " Enter player 1's name: " << Plyr1, cin >> Plyr1;
                            setTConsoleColor(11);
                            cout << "\t\t\t\t" << verticalBorder << " Player 1's name is:    " << Plyr1 << endl;
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << " Enter player 2's name: " << Plyr2, cin >> Plyr2;
                            setTConsoleColor(11);
                            cout << "\t\t\t\t" << verticalBorder << " Player 2's name is:    " << Plyr2 << endl;
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << verticalBorder << "                                         " << verticalBorder << endl;
                            // Input Location format
                            setTConsoleColor(6);
                            cout << "\t\t\t\t" << verticalBorder << "Choose following format to enter input:  " << verticalBorder << endl;
                            cout << "\t\t\t\t" << horizontalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      1      |      2      |      3      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      4      |      5      |      6      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "-----------------------------------------" << verticalBorder << endl;
                            cout << "\t\t\t\t" << verticalBorder << "      7      |      8      |      9      " << verticalBorder << endl;
                            cout << "\t\t\t\t" << horizontalBorder << endl;

                            // Input
                            string winner = PlayerInput(Ttt, &Plyr1, &Plyr2);
                            // Update history
                            history += "The last winner is: " + winner + "\n";
                            // Output
                            Display(&winner, Plyr1, Plyr2);
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