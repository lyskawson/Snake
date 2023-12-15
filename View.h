#include "SFML/Graphics.hpp"
#include "Board.h"


#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H


class View
{

    Board & board;
    sf::Font font;
    sf::Text level[4], scoreboard, exit, timer_text, score, diff, scoreboardT, scoreboardt, textButton;
    sf::Texture grass, snake, fruit, wall, snake_headU, snake_headD, snake_headR, snake_headL, dead_snakeU, dead_snakeD, dead_snakeR, dead_snakeL, background, icon;
    sf::Sprite grassField, snakeField, fruitField, wallField, snake_headFieldU, snake_headFieldD, snake_headFieldR, snake_headFieldL, dead_snakeFieldU, dead_snakeFieldD, dead_snakeFieldR, dead_snakeFieldL, menu_background,snake_icon, button;




public:

    View(Board & board);
    void draw(sf::RenderWindow & window, int spriteSize = 32 );
    std::vector<int> loadScoreboard();


};


#endif //SNAKE_VIEW_H
