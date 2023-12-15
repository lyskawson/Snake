#include "Controller.h"
#include "View.h"
#include "Board.h"




Controller::Controller(Board & board, View & view)
        : board(board), view(view)
{

}

void Controller::play (sf::Event &event)
{
    if(board.getGameState() == RUNNING )
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                if (board.getDirection() == DOWN)
                    return;
                else
                    board.setDirection(UP);
            }
            if (event.key.code == sf::Keyboard::Down)
            {
                if (board.getDirection() == UP)
                    return;
                else
                    board.setDirection(DOWN);
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                if (board.getDirection() == LEFT)
                    return;
                else
                    board.setDirection(RIGHT);
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                if (board.getDirection() == RIGHT)
                    return;
                else
                    board.setDirection(LEFT);
            }
        }

    }
    if (board.getGameState() == MENU)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.key.code == sf::Mouse::Left)
                    {
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 32) {
                            board.setGameMode(EASY);
                            board.setGameState(RUNNING);
                            board.setBoard();
                        }
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 + 64 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 64 + 32) {
                            board.setGameMode(NORMAL);
                            board.setBoard();
                            board.setGameState(RUNNING);
                        }
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 + 128 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 128 + 32) {
                            board.setGameMode(HARD);
                            board.setBoard();
                            board.setGameState(RUNNING);
                        }
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 + 192 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 192 + 32) {
                            board.setGameMode(LEGENDARY);
                            board.setBoard();
                            board.setGameState(RUNNING);
                        }
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 + 256 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 256 + 32) {
                            board.setGameState(SCOREBOARD);
                        }
                        if (event.mouseButton.x > 0 && event.mouseButton.x < 200 &&
                            event.mouseButton.y > board.getBoardHeight() / 10 * 32 + 320 &&
                            event.mouseButton.y < board.getBoardHeight() / 10 * 32 + 320 + 32)
                        {
                            board.setGameState(EXIT);
                        }

                    }

                }


            }
    if (board.getGameState()==SCOREBOARD)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.key.code == sf::Mouse::Left)
            {
                if (event.mouseButton.x > board.getBoardHeight() / 4 * 32 +10 && event.mouseButton.x < board.getBoardWidth() / 4 * 32 + 10 + 220 && event.mouseButton.y > board.getBoardHeight() * 32 - 32 && event.mouseButton.y < board.getBoardHeight() * 32)
                {

                    board.setGameState(MENU);

                }
            }
        }
    }
if(board.getGameState()==FINISHED_LOSS)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.key.code == sf::Mouse::Left)
        {
            if (event.mouseButton.x > board.getBoardHeight() / 4 * 32 +10 && event.mouseButton.x < board.getBoardWidth() / 4 * 32 + 10 + 220 && event.mouseButton.y > board.getBoardHeight() * 32 - 32 && event.mouseButton.y < board.getBoardHeight() * 32)
            {
                board.setBoard();
                board.setGameState(MENU);

            }
        }
    }
}

}