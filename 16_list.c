#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла списка
struct Node {
    int data;
    struct Node* nextNode; // Следующий элемент в текущем списке
    // Следующий элемент в параллельном списке
};

// Функция для добавления нового узла в список
void addNode(struct Node head, int data, struct Node tail) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*tail)->nextNode = newNode;
    }

    *tail = newNode;
}

// Функция для печати содержимого списка
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d\n ", head->data);
        head = head->nextNode;
    }
    printf("\n");
}

// Функция для освобождения памяти, выделенной под список
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->nextNode;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL; // Голова списка
    struct Node *tail = NULL; // Голова списка

    // Ввод элементов в список
    addNode(&head, 1, &tail);
    addNode(&head, 2, &tail);
    addNode(&head, 3, &tail);

    printf("Список: ");
    printList(head); // Вывод содержимого списка

    // Перемещение по списку
    char move;
    struct Node *current = head;
    while (current != NULL) {
        printf("Текущий элемент: %d\n", current->data);
        printf("В какую сторону двигаться (r - вправо): ");
        scanf(" %c", &move);

        if (move == 'r' && current->nextNode != NULL) {
            current = current->nextNode;
        } else {
            printf("Некорректное направление\n");
        }
    }

    // Освобождение памяти
    freeList(head);

    return 0;
}