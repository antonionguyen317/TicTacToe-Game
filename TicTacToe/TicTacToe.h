#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
using namespace std;

class TicTacToe
{
public:
    void drawBoard(char Ttt[][3]);
    string PlayerInput(char Ttt[][3], string* P1, string* P2);
    string Winner(char Ttt[][3], string P1, string P2);
    void Display(string* W, string P1, string P2);
};
#endif // TICTACTOE_H
