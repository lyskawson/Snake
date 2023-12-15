#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <time.h>


enum GameMode  { EASY, NORMAL, HARD, LEGENDARY };
enum GameState { MENU, RUNNING, FINISHED_LOSS, SCOREBOARD, EXIT };
enum Direction {UP, DOWN, RIGHT, LEFT};

struct SnakePart
{
    int x;
    int y;
};

struct Fruit
{
    int x;
    int y;
};

struct Wall
{
    int x;
    int y;
};

class Board
{
    SnakePart snake[300];
    Fruit fruit;
    int width;
    int height;
    Direction direction;
    int snakePartsCount;
    Wall wall[300];
    int fruitEaten;
    int wallsCount;
    GameMode gameMode;
    GameState gameState;



public:
    Board(int w , int h );
    void update();
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getSnakePartsCount() const;
    GameState getGameState() const;
    void setDirection(Direction d);
    int getSnakeX(int i) const;
    int getSnakeY(int i) const;
    int getFruitX() const;
    int getFruitY() const;
    Direction getDirection() const;
    bool checkWallCollision() const;
    void setWalls();
    int getWallX(int i) const;
    int getWallY(int i) const;
    void spawnFruit();
    bool isWall(int x, int y) const;
    bool isSnake(int x, int y) const;
    int getWallsCount() const;
    void setBoard();
    void setGameState(GameState g);
    void setGameMode(GameMode m);
    float getDelay();
    void saveScore();

};

#endif //SNAKE_BOARD_H
