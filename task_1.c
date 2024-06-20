// Задача 1. Среднее арифметическое чисел
// Ввести с клавиатуры массив из 5 элементов, найти среднее арифметическое
// всех элементов массива.
// Данные на входе: 5 целых ненулевых чисел через пробел
// Данные на выходе: Одно число в формате "%.3f"
// Пример №1
// Данные на входе: 4 15 3 10 14
// Данные на выходе: 9.200
// Пример №2
// Данные на входе: 1 2 3 4 5
// Данные на выходе: 3.000

#include <stdio.h>

#define SIZE 5

float find_avr(int *arr, int size) {
    float my_sum;
    for(int i = 0; i < size; i++) {
        my_sum += arr[i];
    }
    return my_sum / size;
}

int main(void) {
    int my_arr[SIZE];
    
    for(int i = 0; i < SIZE; i++) {
        printf("Enter element %d for the array:\n", i + 1);
        scanf("%d", &my_arr[i]);
    }

    printf("\n%.3f", find_avr(my_arr, SIZE));

    return 0;
}
