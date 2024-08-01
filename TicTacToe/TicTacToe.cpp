#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "TicTacToe.h"

using namespace std;

void setTextConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void drawBoard(char Ttt[][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (Ttt[i][j] == 'X')
            {
                setTextConsoleColor(9);
            } else if (Ttt[i][j] == 'O')
            {
                setTextConsoleColor(12);
            } else
            {
                setTextConsoleColor(7);
            }
            cout << Ttt[i][j] << " ";
        }
        setTextConsoleColor(7);
        cout << endl;
    }
}

string PlayerInput(char Ttt[][3], string* P1, string* P2) 
{
    const char* horizontalBorder = "+------------------------------------------+";
    const char* verticalBorder = "|";
    string p1, p2, Win;
    char ReptValu[10] = {};

    for (int i = 0; i < 5; i++) 
    {
        // Player 1 Input
        setTextConsoleColor(11); // Player 1 : Blue
        cout << "\t\t\t\t" << *P1 << "'s turn: ";
        setTextConsoleColor(7); // Reset color
        do 
        {
            cin >> p1;

            if (p1.length() == 1 && p1[0] < 58 && p1[0] > 48 && p1[0] != ReptValu[0] && p1[0] != ReptValu[1]
                && p1[0] != ReptValu[2] && p1[0] != ReptValu[3] && p1[0] != ReptValu[4] && p1[0] != ReptValu[5]
                && p1[0] != ReptValu[6] && p1[0] != ReptValu[7] && p1[0] != ReptValu[8] && p1[0] != ReptValu[9]) 
            {
                cout << endl;
                break;
            }   
            else if (p1[0] == ReptValu[0] || p1[0] == ReptValu[1] || p1[0] == ReptValu[2] || p1[0] == ReptValu[3]
                    || p1[0] == ReptValu[4] || p1[0] == ReptValu[5] || p1[0] == ReptValu[6] || p1[0] == ReptValu[7]
                    || p1[0] == ReptValu[8] || p1[0] == ReptValu[9])
            {
                cout << "\t\t\t\t" << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                cout << "\t\t\t\t" << *P1 << " turn again : ";
            }
            else
            {
                cout << "\t\t\t\t" << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                cout << "\t\t\t\t" << *P1 << " turn again : ";
            }
        } while (true);

        // Storing Player 1 Input in Matrix
        setTextConsoleColor(6);
        if (p1[0] == '1') { Ttt[0][0] = 'X'; }
        if (p1[0] == '2') { Ttt[0][1] = 'X'; }
        if (p1[0] == '3') { Ttt[0][2] = 'X'; }
        if (p1[0] == '4') { Ttt[1][0] = 'X'; }
        if (p1[0] == '5') { Ttt[1][1] = 'X'; }
        if (p1[0] == '6') { Ttt[1][2] = 'X'; }
        if (p1[0] == '7') { Ttt[2][0] = 'X'; }
        if (p1[0] == '8') { Ttt[2][1] = 'X'; }
        if (p1[0] == '9') { Ttt[2][2] = 'X'; }

        // Checking winner if there is.
        Win = Winner(Ttt, *P1, *P2);

        // showing user input in matrix form 
        setTextConsoleColor(11);
        cout << "\t\t\t\t" << horizontalBorder << endl;
        cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[0][0] << "      |      " << Ttt[0][1] << "      |      " << Ttt[0][2] << "       " << verticalBorder << endl;
        cout << "\t\t\t\t" << verticalBorder << "------------------------------------------" << verticalBorder << endl;
        cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[1][0] << "      |      " << Ttt[1][1] << "      |      " << Ttt[1][2] << "       " << verticalBorder << endl;
        cout << "\t\t\t\t" << verticalBorder << "------------------------------------------" << verticalBorder << endl;
        cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[2][0] << "      |      " << Ttt[2][1] << "      |      " << Ttt[2][2] << "       " << verticalBorder << endl;
        cout << "\t\t\t\t" << horizontalBorder << endl;
        cout << endl;

        if (Win == *P1 || Win == *P2) break; // End the game if there's a winner
        else if (i == 4) { Win = "Draw"; break; }// End the game if game is draw
        ReptValu[i] = p1[0];

        // Player 2 Input
            setTextConsoleColor(12); // Red for player 2
            cout << "\t\t\t\t" << *P2 << "'s turn: ";
            setTextConsoleColor(7); // Reset color
            do
            {
                cin >> p2;
                if (p2.length() == 1 && p2[0] > 48 && p2[0] < 58 && p2[0] != p1[0] && p2[0] != ReptValu[0] &&
                p2[0] != ReptValu[1] && p2[0] != ReptValu[2] && p2[0] != ReptValu[3] && p2[0] != ReptValu[4]
                && p2[0] != ReptValu[5] && p2[0] != ReptValu[6] && p2[0] != ReptValu[7] && p2[0] != ReptValu[8]
                && p2[0] != ReptValu[9])
                {
                    cout << endl;
                    break;
                }
                else if (p2[0] == ReptValu[0] || p2[0] == ReptValu[1] || p2[0] == ReptValu[2] || p2[0] == ReptValu[3]
                || p2[0] == ReptValu[4] || p2[0] == ReptValu[5] || p2[0] == ReptValu[6] || p2[0] == ReptValu[7]
                || p2[0] == ReptValu[8] || p2[0] == ReptValu[9])
                {
                    cout << "\t\t\t\t" << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                    cout << "\t\t\t\t" << *P2 << " turn again : ";
                }
                else
                {
                    cout << "\t\t\t\t" << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                    cout << "\t\t\t\t" << *P2 << " turn again : ";
                }
            } while (true);
            
            // Storing Player 2 Input in Matrix
            if (p2[0] == '1') { Ttt[0][0] = 'O'; }
            if (p2[0] == '2') { Ttt[0][1] = 'O'; }
            if (p2[0] == '3') { Ttt[0][2] = 'O'; }
            if (p2[0] == '4') { Ttt[1][0] = 'O'; }
            if (p2[0] == '5') { Ttt[1][1] = 'O'; }
            if (p2[0] == '6') { Ttt[1][2] = 'O'; }
            if (p2[0] == '7') { Ttt[2][0] = 'O'; }
            if (p2[0] == '8') { Ttt[2][1] = 'O'; }
            if (p2[0] == '9') { Ttt[2][2] = 'O'; }

            // Checking winner if there is.
            Win = Winner(Ttt, *P1, *P2);

            // showing user input in matrix form 
            setTextConsoleColor(12);
            cout << "\t\t\t\t" << horizontalBorder << endl;
            cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[0][0] << "      |      " << Ttt[0][1] << "      |      " << Ttt[0][2] << "       " << verticalBorder << endl;
            cout << "\t\t\t\t" << verticalBorder << "------------------------------------------" << verticalBorder << endl;
            cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[1][0] << "      |      " << Ttt[1][1] << "      |      " << Ttt[1][2] << "       " << verticalBorder << endl;
            cout << "\t\t\t\t" << verticalBorder << "------------------------------------------" << verticalBorder << endl;
            cout << "\t\t\t\t" << verticalBorder << "      " << Ttt[2][0] << "      |      " << Ttt[2][1] << "      |      " << Ttt[2][2] << "       " << verticalBorder << endl;
            cout << "\t\t\t\t" << horizontalBorder << endl;
            if (Win == *P1 || Win == *P2) break; // End the game if there's a winner

            // storing value in array for not repeating same input by using in if statement
            ReptValu[i + 5] = p2[0];
    }
    return Win;
}

string Winner(char Ttt[][3], string P1, string P2) {
    string Winner = " ";

    // Check for player 1 as winner
    if ((Ttt[0][0] == 'X' && Ttt[0][1] == 'X' && Ttt[0][2] == 'X') ||
        (Ttt[1][0] == 'X' && Ttt[1][1] == 'X' && Ttt[1][2] == 'X') ||
        (Ttt[2][0] == 'X' && Ttt[2][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][0] == 'X' && Ttt[2][0] == 'X') ||
        (Ttt[0][1] == 'X' && Ttt[1][1] == 'X' && Ttt[2][1] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][2] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][1] == 'X' && Ttt[2][0] == 'X')) 
    {
        Winner = P1;
    }

    // Check for player 2 as winner
    if ((Ttt[0][0] == 'O' && Ttt[0][1] == 'O' && Ttt[0][2] == 'O') ||
        (Ttt[1][0] == 'O' && Ttt[1][1] == 'O' && Ttt[1][2] == 'O') ||
        (Ttt[2][0] == 'O' && Ttt[2][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][0] == 'O' && Ttt[2][0] == 'O') ||
        (Ttt[0][1] == 'O' && Ttt[1][1] == 'O' && Ttt[2][1] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][2] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][1] == 'O' && Ttt[2][0] == 'O')) 
    {
        Winner = P2;
    }

    return Winner;
}

void Display(string* W, string P1, string P2) {
    if (*W == P1 || *W == P2) 
    {
        cout << "\n\n\t\t\t\t The winner is : " << *W << endl << endl;
    } else 
    {
        cout << "\t\t\t\t\t It is a draw game! \n";
    }

    cout << "\t\t\t\t *** Thank you for playing my game. Hope you enjoy it! ***\n";
    cout << "\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";
}
