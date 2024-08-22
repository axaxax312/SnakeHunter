#ifndef SNAKE_H
#define SNAKE_H

class Snake {
private:
    int x, y;
    int tailX[100], tailY[100];
    int nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

public:
    Snake(int startX, int startY);
    void changeDirection(char key);
    void move();
    bool checkCollision(int fruitX, int fruitY);
    bool isCollidingWithSelf();
    int getX();
    int getY();
    void grow();
    void draw();

    // Các hàm thành viên mới
    int getTailLength();
    int getTailX(int index);
    int getTailY(int index);
};

#endif