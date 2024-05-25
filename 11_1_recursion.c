#include <stdio.h>
#include <math.h>

// Рекурсивная функция для вычисления суммы ряда
double sinSeries(double x, int n, double term, double epsilon) {
    if (fabs(term) < epsilon) {
        return term;
    }
    double nextTerm = -term * x * x / ((2 * n) * (2 * n + 1));
    return term + sinSeries(x, n + 1, nextTerm, epsilon);
}

int main() {
    double x = M_PI / 4; // пример для x = π/4
    double epsilon = 1e-3;
    
    // Вызов рекурсивной функции для вычисления суммы ряда
    int n = 1;
    double sum = sinSeries(x, n, x, epsilon);

    // Вычисление точного значения с использованием библиотеки
    double exactValue = sin(x);

    // Печать результата
    printf("Вычисленное значение суммы ряда: %.5f\n", sum);
    printf("Точное значение sin(x) с использованием библиотеки: %.5f\n", exactValue);

    return 0;
}