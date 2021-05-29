#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <cstring>
#include "global.h"

//#define TIC 'X'
//#define TAC 'O'
//#define NO  ' '

class FIELD
{
private :
    int** field;
    int w;
    int h;
    int count_move; //current move, must be less than w*h

    int checkWinner() {
        return ERROR::OK;
    }

public:
    FIELD();
    FIELD(int w_, int h_, int len_line_winner){}
    ~FIELD();

    int MakeMove(int x, int y, char symb = SYMBOL::no);

    void ShowField();
    int getCount_move() const;
    int getMaxMove() const;
};




















#endif // FIELD_H
