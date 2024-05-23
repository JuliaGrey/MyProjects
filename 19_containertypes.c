#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

typedef struct Student {
    int record_book_number;
    char full_name[50];
    char group[10];
    float midterm_score;
} Student;

Student* students = NULL;
int num_students = 0;

void add_student(int record_book_number, char* full_name, char* group, float midterm_score) {
    students = realloc(students, (num_students + 1) * sizeof(Student));//добавление памаяти к уже существующей
    students[num_students].record_book_number = record_book_number;
    strcpy(students[num_students].full_name, full_name);//копируем имя в поле имени стедента
    strcpy(students[num_students].group, group);
    students[num_students].midterm_score = midterm_score;
    num_students++;
}

void remove_students_with_low_scores() {
    int i = 0;
    while (i < num_students) 
    {
        if (students[i].midterm_score < 3)
        {
            for (int j = i; j < num_students - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            num_students--;
        }
        else 
        {
            i++;
        }
    }
}

void print_students() {
    for (int i = 0; i < num_students; i++)
    {
        printf("%d) %d %s %s %.2f\n", i+1, students[i].record_book_number, students[i].full_name, students[i].group, students[i].midterm_score);
    }
}


int main() {
    srand(time(NULL));
    add_student(rand()%899999+100000, "Шестакова Диана Алексеевна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Селезнева Арина Артёмовна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Панова Алиса Дмитриевна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Яковлев Глеб Константинович", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Копылов Михаил Егорович", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Попова Полина Александровна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Блинов Лев Кириллович", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Евдокимова София Мирославовна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Горелова Мария Кирилловна", "ИС-23",rand()%5+1);
    add_student(rand()%899999+100000, "Николаева София Максимовна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Родионов Марк Миронович", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Русанова Варвара Дмитриевна", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Самсонов Григорий Алексеевич", "ИС-23",rand()%5+1);
    add_student(rand()%899999+100000, "Лавров Артём Миронович", "ИС-23", rand()%5+1);
    add_student(rand()%899999+100000, "Серова Кристина Егоровна", "ИС-23", rand()%5+1);

    printf("Все студенты:\n");
    print_students();

    int d;
    while (1)
    {    
    printf("\nХотите добавить студента ? [1/0]\n");
    scanf("%d",&d);
    if(d == 0)
    {
        break;
    }
    char name[50], group[10];
    int h, b;
    
    printf("Номер зачётки: ");
    scanf("%d", h);

    printf("ФИО: ");
    scanf("%c", name);

    printf("Группа: ");
    scanf("%c", group);

    printf("Балл: ");
    scanf("%d", b);

    add_student(h,name,group,b);
    }

    printf("Все студенты:\n");
    print_students();


    printf("\n\nСтуденты с хорошим балом:\n");
    remove_students_with_low_scores();
    print_students();

    return 0;
}
