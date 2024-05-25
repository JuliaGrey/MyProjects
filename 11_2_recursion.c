#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Рекурсивная функция для нахождения максимального элемента в пределах от -1.2 до 5.8
float findMaxRec(float arr[], int size, float max) {
    // Базовый случай: если массив пуст, возвращаем текущий максимум
    if (size == 0) {
        return max;
    }

    // Рекурсивный случай: проверяем текущий элемент
    if (arr[size - 1] >= -1.21 && arr[size - 1] <= 5.81) {
        if (arr[size - 1] > max) {
            max = arr[size - 1];
        }
    }

    // Рекурсивно вызываем функцию для оставшейся части массива
    return findMaxRec(arr, size - 1, max);
}

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // Выделяем память под динамический массив
    float *arr = (float *)malloc(n * sizeof(float));

    // Заполняем массив значениями
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Находим максимальный элемент
    float max = findMaxRec(arr, n, -INFINITY);

    // Выводим результат
    printf("Максимальный элемент в пределах от -1.2 до 5.8: %.2f\n", max);

    // Освобождаем выделенную память
    free(arr);

    return 0;
}