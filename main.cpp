#include <SFML/Graphics.hpp>
#include <time.h>
#include "Controller.h"
#include "View.h"
#include "Board.h"

int main()
{


    srand(time(0));
    Board board(31,26);
    View view(board);
    Controller ctrl(board, view);
    sf::RenderWindow window(sf::VideoMode(board.getBoardWidth()*32, board.getBoardHeight()*32 ), "Snake");
    sf::Clock clock;
    float timer=0;




    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer = timer + time;

        sf::Event event;
        while (window.pollEvent(event))
        {
        if (event.type == sf::Event::Closed || board.getGameState()==EXIT)
                window.close();
        }


        ctrl.play(event);
        window.clear();
        view.draw(window);
        window.display();
        if (timer  >= board.getDelay())
        {
            timer = 0;
            board.update();
        }
    }
        return 0;

    }


