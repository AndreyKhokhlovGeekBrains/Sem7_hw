// Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
// Данные на входе: 5 целых чисел через пробел
// Данные на выходе: Одно единственное целое число
// Пример №1
// Данные на входе: 4 15 3 10 14
// Данные на выходе: 3
// Пример №2
// Данные на входе: 1 2 3 4 -5
// Данные на выходе: -5

#include <stdio.h>

#define SIZE 5

int find_min(int *arr, int size) {
    int my_min = arr[0];
    for(int i = 1; i < size; i++) {
        if(my_min > arr[i]) {
            my_min = arr[i];
        }
    }
    return my_min;
}

int main(void) {
    int my_arr[SIZE];
    
    for(int i = 0; i < SIZE; i++) {
        printf("Enter element %d for the array:\n", i + 1);
        scanf("%d", &my_arr[i]);
    }

    printf("\n%d", find_min(my_arr, SIZE));

    return 0;
}
