#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>

using namespace std;

// функция для нахождения НОД
uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// вычисление суммы ряда
string calculateSum(uint64_t a, uint64_t b) {

    // проверка сходимости ряда
    if (b <= 1) {
        return "infinity";
    }

    uint64_t numerator = 0;
    uint64_t denominator = 1;

    // формулы суммы ряда
    switch (a) {

        case 1:
            numerator = b;
            denominator = (b - 1) * (b - 1);
            break;

        case 2:
            numerator = b * (b + 1);
            denominator = pow(b - 1, 3);
            break;

        case 3:
            numerator = b * (b * b + 4 * b + 1);
            denominator = pow(b - 1, 4);
            break;

        case 4:
            numerator = b * (b * b * b + 11 * b * b + 11 * b + 1);
            denominator = pow(b - 1, 5);
            break;

        // остальные случаи a = 5..10
        default: {

            double sum = 0.0;

            for (uint64_t n = 1; n <= 100000; n++) {
                sum += pow(n, a) / pow(b, n);
            }

            const uint64_t PRECISION = 1000000;

            numerator = round(sum * PRECISION);
            denominator = PRECISION;

            break;
        }
    }

    // защита от деления на ноль
    if (denominator == 0) {
        return "error";
    }

    // сокращение дроби
    uint64_t g = gcd(numerator, denominator);

    numerator /= g;
    denominator /= g;

    // формирование результата
    return to_string(numerator) + "/" + to_string(denominator);
}

int main() {

    int64_t a, b;

    cout << "Введите a и b: ";
    cin >> a >> b;

    // проверка корректности ввода
    if (cin.fail()) {
        return 0;
    }

    // проверка диапазона
    if (a < 1 || a > 10 || b < 1 || b > 10) {
        return 0;
    }

    // вычисление результата
    string result = calculateSum((uint64_t)a, (uint64_t)b);

    // вывод результата
    cout << "Результат: " << result << endl;

    return 0;
}
