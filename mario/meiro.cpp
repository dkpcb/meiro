#include <iostream>
#include <conio.h>  // For _getch() function
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;
char maze[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', 'P', '#', '#', '#', '#', '#', '#', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int playerX = 1;
int playerY = 8;

void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            cout << maze[y][x];
        }
        cout << endl;
    }
}

bool movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;
    switch (direction) {
    case 'w': newY--; break;
    case 's': newY++; break;
    case 'a': newX--; break;
    case 'd': newX++; break;
    }

    if (maze[newY][newX] == ' ' || maze[newY][newX] == 'E') {
        maze[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        maze[playerY][playerX] = 'P';
        return true;
    }
    return false;
}

int main() {
    bool isGameOver = false;
    while (!isGameOver) {
        printMaze();
        char input = _getch();
        if (input == 'q') break;
        if (movePlayer(input)) {
            if (maze[playerY][playerX] == 'E') {
                cout << "You found the exit! Congratulations!" << endl;
                isGameOver = true;
            }
        }
    }
    return 0;
}
