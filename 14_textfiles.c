#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    int num_lines = 10; // Произвольное количество строк
    int num_numbers = 0;

    file = fopen("text_file.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < rand() % 10 + 1; j++) {
            int num = rand() % 100; // Генерируем случайное число от 0 до 99
            fprintf(file, "%d ", num);
            num_numbers++;
        }
        fprintf(file, "\n");
    }

    fprintf(file, "Количество чисел: %d", num_numbers);

    fclose(file);

    printf("Файл успешно создан.\n");

    return 0;
}