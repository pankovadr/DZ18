#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
struct Film {
    char name[50];    
    char date[15];    
    int hour;         
    int min;      
    int dur;         
    char genre[20]; 
    float budget;   
};

int main() {
    setlocale(LC_ALL, "RUS");
    struct Film f[10]; 
    int n, i;

    printf("Сколько фильмов ввести? (5-10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nФильм %d:\n", i + 1);
        printf("Название (одним словом): ");
        scanf("%s", f[i].name);
        printf("Дата: ");
        scanf("%s", f[i].date);
        printf("Время (часы и минуты через пробел): ");
        scanf("%d %d", &f[i].hour, &f[i].min);
        printf("Длительность (в минутах): ");
        scanf("%d", &f[i].dur);
        printf("Жанр: ");
        scanf("%s", f[i].genre);
        printf("Бюджет: ");
        scanf("%f", &f[i].budget);
    }

    printf("\n--- Подходящие фильмы ---\n");
    int count = 0;

    for (i = 0; i < n; i++) {
   
        if ((f[i].hour > 18 || (f[i].hour == 18 && f[i].min > 0)) && f[i].dur > 100) {
            printf("%s | %s | %d:%02d | %d мин | %s | %.2f\n",
                f[i].name, f[i].date, f[i].hour, f[i].min, f[i].dur, f[i].genre, f[i].budget);
            count++;
        }
    }

    if (count == 0) {
        printf("Ничего не найдено.\n");
    }

    return 0;
}