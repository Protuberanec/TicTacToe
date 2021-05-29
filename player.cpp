#include "player.h"



PLAYER::PLAYER(FIELD *field, int type_pl, char symbol_player)
{
    type_player = type_pl;
    symbol = symbol_player;
    current_field = field;

    my_move = false;
    if (symbol_player == SYMBOL::tac) {
        my_move = true;
    }
}

int PLAYER::MakeMove(int x, int y)
{
    if (type_player == TYPE_PLAYER::human)
    {
        return current_field->MakeMove(x,y, symbol);
    }
//from here need make an AI

    std::pair<int,int> coor = GetBetterMove();
    current_field->MakeMove(coor.first, coor.second, symbol);

    return ERROR::NOT_MY_MOVE;
}
