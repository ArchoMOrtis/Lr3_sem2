#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void table() {
    cout << "|    x    |     y     |" << endl;
    cout << "------------------------" << endl;
}

void printTable(float x, float y) {
    cout << "|" << setw(8) << fixed << setprecision(1) << x << " |"
         << setw(10) << fixed << setprecision(2) << y << " |" << endl;
}

void printEnd() {
    cout << "------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    float x, y;
    float dx = 0.5;

    cout << "Таблица значений функции:\n";

    printEnd();
    table();

    // 1. Прямая [-5; -2]
    for (x = -5; x < -2; x += dx) {
        y = -x - 2;
        printTable(x, y);
    }

    // 2. Четверть окружности [-2; -1]
    for (x = -2; x < -1; x += dx) {
        y = sqrt(1 - pow(x + 1, 2));
        printTable(x, y);
    }

    // 3. Горизонтальный участок [-1; 1]
    for (x = -1; x < 1; x += dx) {
        y = 1;
        printTable(x, y);
    }

    // 4. Прямая [1; 2]
    for (x = 1; x < 2; x += dx) {
        y = -2 * x + 3;
        printTable(x, y);
    }

    // 5. Парабола [2; 6]
    for (x = 2; x <= 6; x += dx) {
        y = pow(x - 2, 2) / 8 - 1;
        printTable(x, y);
    }

    printEnd();

    return 0;
}
