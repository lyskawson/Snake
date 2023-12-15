#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "View.h"


class Controller
{
    Board &board;
    View &view;

public:
    Controller(Board & board, View & view);
    void play(sf::Event & event);


};


#endif //SNAKE_CONTROLLER_H
