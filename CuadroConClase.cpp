#include <iostream>
#include <windows.h>
#include <conio.h>

class Cuadrado {
private:
    char cuadrado[2][2];
    int x, y;

public:
    Cuadrado() {
        cuadrado[0][0] = '*';
        cuadrado[0][1] = '*';
        cuadrado[1][0] = '*';
        cuadrado[1][1] = '*';
        x = 0;
        y = 0;
    }

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void draw() {
        for (int f = 0; f < 2; f++) {
            for (int c = 0; c < 2; c++) {
                gotoxy(x + c, y + f);
                std::cout << cuadrado[f][c] << " ";
            }
        }
    }

    void move(char direccion) {
        switch (direccion) {
        case 'a':
            x--;
            break;
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        }
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

int main() {
    Cuadrado cuadrado;
    int actual = 1;
    char direccion;

    while (actual) {
        system("cls");
        cuadrado.draw();
        direccion = _getch();

        if (direccion == 'q') {
            actual = 0;
        }
        else {
            cuadrado.move(direccion);
        }
    }

    return 0;
} 
