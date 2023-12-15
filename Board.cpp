#include "Board.h"
#include <cmath>
#include <fstream>
#include <iostream>

Board::Board(int w, int h)
{
    width = w;
    height = h;
    setGameState(MENU);
    setBoard();
}


void Board::update()
{
    if(getGameState() == RUNNING)
    {
        for (int i = snakePartsCount; i > 0; i--) //podarzanie weza za koljenymi segmentami
        {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        if (direction == UP) // poruszanie sie w danym kierunku
            snake[0].y = snake[0].y - 1;
        if (direction == DOWN)
            snake[0].y = snake[0].y + 1;
        if (direction == RIGHT)
            snake[0].x = snake[0].x + 1;
        if (direction == LEFT)
            snake[0].x = snake[0].x - 1;

        if ((snake[0].x == fruit.x) && (snake[0].y == fruit.y)) //losuje nowe  wspolrzedne jablka po zjedzeniu
        {
            spawnFruit();
           snakePartsCount++;
           fruitEaten ++;
        }

        for (int i = 1; i < snakePartsCount; i++)
        {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)  //jedzenie sie przez weza
                snakePartsCount = i;
        }
        if(isWall(snake[0].x, snake[0].y))
            saveScore();
    }
}

int Board::getBoardWidth() const
{
    return width;
}

int Board::getBoardHeight() const
{
    return height;
}

int Board::getSnakePartsCount() const
{
    return snakePartsCount;
}

GameState Board::getGameState() const
{
    if(checkWallCollision()==true)
    {

        return FINISHED_LOSS;
    }
    else
        return gameState;
}

void Board::setDirection(Direction d)
{
    direction =  d;
}

int Board::getSnakeX(int i) const
{
    return snake[i].x;
}

int Board::getSnakeY(int i) const
{
    return snake[i].y;
}

int Board::getFruitX() const
{
    return fruit.x;
}

int Board::getFruitY() const
{
    return fruit.y;
}

Direction Board::getDirection() const
{
    return direction;
}

bool Board::checkWallCollision() const
{
    if(isWall(snake[0].x, snake[0].y))
        return true;
    else
        return false;
}

void Board::setWalls()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
            {
                wall[wallsCount].x = i;
                wall[wallsCount].y = j;
                wallsCount++;
            }
            else if (i == 4 && j == 4)
            {
                for (int a = 0; a < 7; a++)
                {
                    wall[wallsCount].x = i + a;
                    wall[wallsCount].y = j + a;
                    wallsCount++;
                }
            }
            else if (i == 4 && j == 21 )
            {
                for (int a = 0; a < 7; a++)
                {
                    wall[wallsCount].x = i + a;
                    wall[wallsCount].y = j - a;
                    wallsCount++;
                }
            }
            else if (i == 25 && j == 4 )
            {
                for (int a = 0; a < 7; a++)
                {
                    wall[wallsCount].x = i - a;
                    wall[wallsCount].y = j + a;
                    wallsCount++;
                }
            }
            else if (i == 25 && j == 21 )
            {
                for (int a = 0; a < 7; a++)
                {
                    wall[wallsCount].x = i - a;
                    wall[wallsCount].y = j - a;
                    wallsCount++;
                }
            }
        }
    }
}

int Board::getWallX(int i) const
{
    return wall[i].x;
}

int Board::getWallY(int i) const
{
    return wall[i].y;
}

void Board::spawnFruit()
{
    int a, b;

    do
    {
        a = rand() % width;
        b = rand() % height;
    }
    while (isWall(a, b) || isSnake(a,b) );

    fruit.x = a;
    fruit.y = b;
}

bool Board::isWall(int x, int y ) const
{
    for (int i=0; i <wallsCount; i++)
    {
        if(x  == wall[i].x && y == wall[i].y)
            return true;
    }
    return false;
}

bool Board::isSnake(int x, int y)  const
{
    for (int i=0; i<snakePartsCount; i++)
    {
        if(x == snake[i].x && y == snake[i].y)
            return true;
    }
    return false;
}

int Board::getWallsCount() const
{
    return wallsCount;
}

float Board::getDelay()
{
    if(gameMode == EASY)
        return 0.27;
    if(gameMode == NORMAL)
        return  0.2;
    if(gameMode == HARD)
        return 0.1;
    if(gameMode == LEGENDARY)
        return 0.06;
}

void Board::setBoard()
{
    snakePartsCount = 4;
    direction = DOWN;
    fruitEaten = 0;
    wallsCount = 0;
    snake[0].x = getBoardWidth() / 2;
    snake[0].y = getBoardHeight() / 2;
    setWalls();
    spawnFruit();
}

void Board::setGameState(GameState g)
{
    gameState = g;

}

void Board::setGameMode(GameMode m)
{
    gameMode = m;

}



void Board::saveScore()
{
    if(getGameState()==FINISHED_LOSS)
    {
        std::ofstream f;
        f.open("../scoreboard.txt", std::ios::app);
        f << snakePartsCount << std::endl;
        f.close();
    }
}



