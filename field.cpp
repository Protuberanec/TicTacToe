#include "field.h"

using namespace std;

//#define USE_MEMSET
int FIELD::getCount_move() const
{
    return count_move;
}

int FIELD::getMaxMove() const
{
    return w * h;
}

FIELD::FIELD()
{
    count_move = 0;
    w = 3;
    h = 3;
    field = new int *[h];
    for (int i = 0; i < h; i++) {
        field[i] = new int [w];
#ifndef USE_MEMSET
        for (int j = 0; j < w; j++) {
            field[i][j] = SYMBOL::no;
        }
#endif
    }
#ifdef USE_MEMSET
    memset(field, no, w*h*sizeof(int));    //0x20202020
#endif
}

FIELD::~FIELD()
{
    for (int i = 0; i < h; i++) {
        delete [] field[i];
    }
    delete [] field;
}

int FIELD::MakeMove(int x, int y, char symb)
{
    if (field[x][y] != SYMBOL::no) {
        return ERROR::FIELD_BUSY;
    }

    if (count_move == 9) {
        return ERROR::NO_FREE_PLACE;
    }

    field[x][y] = symb;



    ++count_move;

    return checkWinner();
}

void FIELD::ShowField()
{
    system("cls");

    cout << " |";
    for (int i = 0; i < w; i++) {
        cout << i << "|";
    }
    cout << endl;
    for (int y = 0; y < h; y++) {
        cout << y << "|";
        for (int x = 0; x < w; x++) {
            cout << (char)field[x][y] << "|";
        }
        cout << endl;
    }
    cout << endl;
}

















