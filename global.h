#ifndef GLOBAL_H
#define GLOBAL_H

enum SYMBOL{
    tic = 'X',
    tac = 'O',
    no = '_',   //0x20
};

enum ERROR {
    OK = 0,
    FIELD_BUSY = 1,
    NO_FREE_PLACE,
    WIN,
    NOT_MY_MOVE,
};

enum TYPE_PLAYER {
    reserved = 0,
    human = 1,
    AI = 2,
};


#endif // GLOBAL_H
