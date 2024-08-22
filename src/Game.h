#ifndef GAME_H
#define GAME_H

#include "Snake.h"

class Game {
private:
    bool gameOver;
    int fruitX, fruitY, score;
    Snake snake;
    const int width = 20;
    const int height = 17;

public:
    Game();
    void Setup();
    void Draw();
    void Input();
    void Logic();
    bool isGameOver();
    void Sleep(int ms);
};

#endif