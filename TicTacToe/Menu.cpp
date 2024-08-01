#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"

using namespace std;

void setConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Menu(int selected) {
    system("cls"); // Clear the console

    // Define border characters
    
    const char* horizontalBorder = "+----------------------------------------+";
    const char* verticalBorder = "|";
    
    setConsoleColor(11);
    cout << "\t\t\t\t\t* How to play: \n";
    cout << "\t\t\t\t\t- Use arrow keys to navigate.\n";
    cout << "\t\t\t\t\t- Enter to select.\n\n";

    // Print the top border
    setConsoleColor(6);
    cout << "\t\t\t\t" << horizontalBorder << endl;

    // Print the menu with a border
    setConsoleColor(6);
    cout << "\t\t\t\t" << verticalBorder << "                                        " << verticalBorder << endl;
    cout << "\t\t\t\t" << verticalBorder << "               Tic-Tac-Toe              " << verticalBorder << endl;
    cout << "\t\t\t\t" << verticalBorder << "                                        " << verticalBorder << endl;
    cout << "\t\t\t\t" << verticalBorder << "----------------------------------------" << verticalBorder << endl;
    cout << "\t\t\t\t" << verticalBorder << "                                        " << verticalBorder << endl;
    setConsoleColor(selected == 1 ? 11 : 6); // Blue for selected, grey for others
    cout << "\t\t\t\t" << verticalBorder << (selected == 1 ? "-> " : "   ") << " 1. Play" << "                             " << verticalBorder << endl;

    setConsoleColor(selected == 2 ? 11 : 6);
    cout << "\t\t\t\t" << verticalBorder << (selected == 2 ? "-> " : "   ") << " 2. History" << "                          " << verticalBorder << endl;

    setConsoleColor(selected == 3 ? 11 : 6);
    cout << "\t\t\t\t" << verticalBorder << (selected == 3 ? "-> " : "   ") << " 3. Exit" << "                             " << verticalBorder << endl;

    // Print the bottom border
    setConsoleColor(6);
    cout << "\t\t\t\t" << verticalBorder << "                                        " << verticalBorder << endl;
    cout << "\t\t\t\t" << horizontalBorder << endl;
}
