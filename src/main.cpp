#include "Game.h"

int main() {
    Game game;
    game.Setup();
    
    while (!game.isGameOver()) {
        game.Draw();
        game.Input();
        game.Logic();
        game.Sleep(1000); // Điều chỉnh thời gian nghỉ để điều khiển tốc độ game
    }

    return 0;
}