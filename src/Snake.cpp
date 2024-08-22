#include "Snake.h"
#include <iostream>

Snake::Snake(int startX, int startY) {
    x = startX;
    y = startY;
    nTail = 0;
    dir = STOP;
}

void Snake::changeDirection(char key) {
    switch (key) {
    case 'a': dir = LEFT; break;
    case 'd': dir = RIGHT; break;
    case 'w': dir = UP; break;
    case 's': dir = DOWN; break;
    }
}

void Snake::move() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    default: break;
    }
}

bool Snake::checkCollision(int fruitX, int fruitY) {
    return (x == fruitX && y == fruitY);
}

bool Snake::isCollidingWithSelf() {
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            return true;
        }
    }
    return false;
}

int Snake::getX() {
    return x;
}

int Snake::getY() {
    return y;
}

void Snake::grow() {
    nTail++;
}

void Snake::draw() {
    std::cout << "O";
}

int Snake::getTailLength() {
    return nTail;
}

int Snake::getTailX(int index) {
    return tailX[index];
}

int Snake::getTailY(int index) {
    return tailY[index];
}