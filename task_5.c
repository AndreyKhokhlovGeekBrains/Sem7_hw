// Задача 5. Вторая с конца ноль
// Считать массив из 10 элементов и отобрать в другой массив все числа, у
// которых вторая с конца цифра (число десятков) – ноль.
// Данные на входе: 10 целых чисел через пробел.
// Данные на выходе: Целые числа через пробел, у которых вторая с конца
// цифра - ноль
// Пример
// Данные на входе: 40 105 203 1 14 1000 22 33 44 55
// Данные на выходе: 105 203 1 1000

#include <stdio.h>

#define SIZE 10

void print_arr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void read_arr(int *arr, int size) {
    int n;
    if(size == 0) return;
    
    while (scanf("%d", &n) == 0)
    {
        /*
        The loop effectively discards all characters in the input buffer up to and including the next newline character.
        This clears any leftover characters (like non-numeric input) that caused scanf to fail, so the next attempt to read input can start fresh.  
        */
        while(getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Enter valid integers for the array:\n");
    }
    
    arr[SIZE - size] = n;
    read_arr(arr, --size);
}

void select_elements(int *arr, int size) {
    int new_arr[size];
    int id = 0;

    for(int i = 0; i < size; i++) {
        if( (arr[i] % 100) / 10 == 0) {
            new_arr[id++] = arr[i];
        }
    }
    print_arr(new_arr, id);
}


int main(void) {
    int my_arr[SIZE];
    printf("Enter the elements for the array:\n");
    read_arr(my_arr, SIZE);
    select_elements(my_arr, SIZE);

    return 0;
}
