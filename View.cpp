#include "View.h"
#include <fstream>
#include <iostream>
#include <vector>


View::View(Board & board) : board(board) {

    //zaladowanie tekstur z pliku
    grass.loadFromFile("../Textures/grass.png");
    snake.loadFromFile("../Textures/snake.png");
    snake_headU.loadFromFile("../Textures/snake_headU.png");
    fruit.loadFromFile("../Textures/fruit.png");
    wall.loadFromFile("../Textures/wall.png");
    snake_headD.loadFromFile("../Textures/snake_headD.png");
    snake_headR.loadFromFile("../Textures/snake_headR.png");
    snake_headL.loadFromFile("../Textures/snake_headL.png");
    dead_snakeU.loadFromFile("../Textures/dead_snakeU.png");
    dead_snakeD.loadFromFile("../Textures/dead_snakeD.png");
    dead_snakeR.loadFromFile("../Textures/dead_snakeR.png");
    dead_snakeL.loadFromFile("../Textures/dead_snakeL.png");
    background.loadFromFile("../Textures/background.png");
    icon.loadFromFile("../Textures/icon.png");


    //ustawienie tekstur na duszki
    grassField.setTexture(grass);
    snakeField.setTexture(snake);
    fruitField.setTexture(fruit);
    wallField.setTexture(wall);
    snake_headFieldU.setTexture(snake_headU);
    snake_headFieldD.setTexture(snake_headD);
    snake_headFieldR.setTexture(snake_headR);
    snake_headFieldL.setTexture(snake_headL);
    dead_snakeFieldU.setTexture(dead_snakeU);
    dead_snakeFieldD.setTexture(dead_snakeD);
    dead_snakeFieldR.setTexture(dead_snakeR);
    dead_snakeFieldL.setTexture(dead_snakeL);
    menu_background.setTexture(background);
    snake_icon.setTexture(icon);
    button.setTexture(background);

    //skalowanie duszkow
    snake_headFieldU.setScale(sf::Vector2f(0.25, 0.25));
    snake_headFieldD.setScale(sf::Vector2f(0.25, 0.25));
    snake_headFieldR.setScale(sf::Vector2f(0.25, 0.25));
    snake_headFieldL.setScale(sf::Vector2f(0.25, 0.25));
    dead_snakeFieldD.setScale(sf::Vector2f(0.25, 0.25));
    dead_snakeFieldU.setScale(sf::Vector2f(0.25, 0.25));
    dead_snakeFieldL.setScale(sf::Vector2f(0.25, 0.25));
    dead_snakeFieldR.setScale(sf::Vector2f(0.25, 0.25));
    fruitField.setScale(sf::Vector2f(0.25, 0.25));
    menu_background.setScale(sf::Vector2f(board.getBoardWidth()*32+64/240, board.getBoardHeight()*32 +64/240));
    snake_icon.setScale(sf::Vector2f(0.7,0.7));
    button.setScale(sf::Vector2f(0.95,0.7));
    snake_icon.setPosition(sf::Vector2f(board.getBoardWidth()/2*15, (board.getBoardHeight()/2*15)));
    button.setPosition(board.getBoardWidth()/4*32, board.getBoardHeight()*32-32);

    snake_icon.setPosition(sf::Vector2f(board.getBoardWidth()/2*15, (board.getBoardHeight()/2*15)));

    //TEXT
    font.loadFromFile("../Textures/Pixels.ttf");
    level[0].setFont(font);
    level[0].setColor(sf::Color::Green);
    level[0].setString("EASY");
    level[0].setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32));
    level[1].setFont(font);
    level[1].setColor(sf::Color::Yellow);
    level[1].setString("NORMAL");
    level[1].setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32+64));
    level[2].setFont(font);
    level[2].setColor(sf::Color::Red);
    level[2].setString("HARD");
    level[2].setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32+128));
    level[3].setFont(font);
    level[3].setColor(sf::Color::Cyan);
    level[3].setString("LEGENDARY");
    level[3].setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32+192));
    scoreboard.setFont(font);
    scoreboard.setColor(sf::Color::White);
    scoreboard.setString("Scoreboard");
    scoreboard.setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32+256));
    exit.setFont(font);
    exit.setColor(sf::Color::White);
    exit.setString("Exit");
    exit.setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)*32+320));
    menu_background.setPosition(sf::Vector2f(0, 0));
    score.setFont(font);
    score.setPosition(32, board.getBoardHeight()*32-32);
    score.setColor(sf::Color::White);
    scoreboardT.setPosition(32, (board.getBoardHeight()/10)*32);
    scoreboardT.setFont(font);
    scoreboardT.setColor(sf::Color::White);
    scoreboardT.setString("SCOREBOARD:  ");
    scoreboardT.setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)));
    scoreboardT.setCharacterSize(85);
    scoreboardt.setPosition(32, (board.getBoardHeight()/10)*32);
    scoreboardt.setFont(font);
    scoreboardt.setColor(sf::Color::White);
    scoreboardt.setPosition(sf::Vector2f(32, (board.getBoardHeight()/10)));

    textButton.setFont(font);
    textButton.setPosition(32, board.getBoardHeight()*32-32);
    textButton.setColor(sf::Color::White);
    textButton.setPosition(board.getBoardWidth()/4*32+5, board.getBoardHeight()*32-32);
    textButton.setString("BACK TO MENU");




}




void View::draw (sf::RenderWindow & window, int spriteSize)
{
    if(board.getGameState()==RUNNING || board.getGameState()==FINISHED_LOSS)
    {

        //TRAWA
        for (int i = 0; i < board.getBoardWidth(); i++) {
            for (int j = 0; j < board.getBoardHeight(); j++) {
                grassField.setPosition(i * spriteSize, j * spriteSize);
                window.draw(grassField);
            }
        }
        //MURKI
        for (int i = 0; i < board.getWallsCount(); i++) {
            wallField.setPosition(board.getWallX(i) * spriteSize, board.getWallY(i) * spriteSize);
            window.draw(wallField);
        }
        //WAZ GLOWA
        if (board.getDirection() == UP) {
            if (board.getGameState() == RUNNING ) {
                snake_headFieldU.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(snake_headFieldU);
            }
            if (board.getGameState() == FINISHED_LOSS) {
                dead_snakeFieldU.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(dead_snakeFieldU);
            }
        }
        if (board.getDirection() == DOWN) {
            if (board.getGameState() == RUNNING) {
                snake_headFieldD.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(snake_headFieldD);
            }
            if (board.getGameState() == FINISHED_LOSS) {
                dead_snakeFieldD.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(dead_snakeFieldD);
            }
        }
        if (board.getDirection() == RIGHT) {
            if (board.getGameState() == RUNNING ) {
                snake_headFieldR.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(snake_headFieldR);
            }
            if (board.getGameState() == FINISHED_LOSS) {
                dead_snakeFieldR.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(dead_snakeFieldR);
            }
        }
        if (board.getDirection() == LEFT) {
            if (board.getGameState() == RUNNING ) {
                snake_headFieldL.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(snake_headFieldL);
            }
            if (board.getGameState() == FINISHED_LOSS) {
                dead_snakeFieldL.setPosition(board.getSnakeX(0) * spriteSize, board.getSnakeY(0) * spriteSize);
                window.draw(dead_snakeFieldL);
            }
        }
        //WAZ CIALO
        for (int i = 1; i < board.getSnakePartsCount(); i++) {
            snakeField.setPosition(board.getSnakeX(i) * spriteSize, board.getSnakeY(i) * spriteSize);
            window.draw(snakeField);
        }
        //OWOCE
        fruitField.setPosition(board.getFruitX() * spriteSize, board.getFruitY() * spriteSize);
        window.draw(fruitField);
        //TEXT
        score.setString("SCORE: " + std::to_string(board.getSnakePartsCount() ));
        window.draw(score);
        window.draw(button);
        window.draw(textButton);

    }
    if(board.getGameState()==MENU)
    {
        window.draw(menu_background);
        for(int i=0; i < 4; i++)
        {
            window.draw(level[i]);
        }
        window.draw(scoreboard);
        window.draw(exit);
        window.draw(snake_icon);
    }
    if(board.getGameState()==SCOREBOARD)
    {

        std::vector<int> scoreboard = loadScoreboard();
        window.draw(menu_background);
        window.draw(scoreboardT);


        for (int i = 0; i < 10; i++)
        {
            int score = scoreboard[i];
            scoreboardt.setPosition(32, 96 + 64 * i);
            scoreboardt.setString(std::to_string(i+1) + "." + std::to_string(   score ));
            window.draw(scoreboardt);
        }
        window.draw(button);
        window.draw(textButton);


    }

}

std::vector<int> View::loadScoreboard() //funkcja w calosci napisana przez chatGPT
{

    std::vector<int> scores;
    std::ifstream file("../scoreboard.txt");

    if (!file.is_open())
    {

        std::cout << "Can't open file!" << std::endl;
    }
    else
    {
        int score;
        while (file >> score)
        {
            scores.push_back(score);
        }
        file.close();
    }

    std::sort(scores.begin(), scores.end(), std::greater<int>());

    return scores;
}



