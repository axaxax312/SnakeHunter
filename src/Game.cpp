#include "Game.h"
#include <iostream>
#include <conio.h> // Thư viện cho _kbhit(), _getch()
#include <windows.h> // Thư viện cho Sleep()

Game::Game() : snake(width / 2, height / 2) {
    gameOver = false;
    score = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Game::Setup() {
    gameOver = false;
    score = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Game::Draw() {
    system("cls"); // Xóa màn hình

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                std::cout << "#";
            if (i == snake.getY() && j == snake.getX())
                snake.draw();
            else if (i == fruitY && j == fruitX)
                std::cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < snake.getTailLength(); k++) {
                    if (snake.getTailX(k) == j && snake.getTailY(k) == i) {
                        std::cout << "o";
                        print = true;
                        break; // Không cần kiểm tra thêm nữa
                    }
                }
                if (!print)
                    std::cout << " ";
            }
            if (j == width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;
}

void Game::Input() {
    if (_kbhit()) {
        snake.changeDirection(_getch());
    }
}

void Game::Logic() {
    snake.move();

    if (snake.isCollidingWithSelf()) {
        gameOver = true;
    }

    if (snake.checkCollision(fruitX, fruitY)) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        snake.grow();
    }
}

bool Game::isGameOver() {
    return gameOver;
}

void Game::Sleep(int ms) {
    ::Sleep(ms); // Thay đổi thời gian ngủ để điều chỉnh tốc độ game
}