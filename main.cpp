#include <QCoreApplication>
#include <iostream>

#include "field.h"
#include "player.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FIELD *field_TicTacToe = new FIELD();

    PLAYER *first = new PLAYER(field_TicTacToe,
                               TYPE_PLAYER::human,
                               SYMBOL::tic);

    PLAYER *second = new PLAYER(field_TicTacToe,
                               TYPE_PLAYER::AI,
                               SYMBOL::tac);
    field_TicTacToe->ShowField();

    int x = 0;
    int y = 0;

    while(field_TicTacToe->getCount_move() < field_TicTacToe->getMaxMove()) {
        do {
            cout << "first player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
        }while (first->MakeMove(x, y) != ERROR::OK);
        field_TicTacToe->ShowField();

        do {
            cout << "second player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
        }while (second->MakeMove(x, y) != ERROR::OK);
        field_TicTacToe->ShowField();

    }

    delete first;
    delete second;
    delete field_TicTacToe;

    return a.exec();
}
