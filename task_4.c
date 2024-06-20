// Задача 4. Отсортировать по последней цифре
// Считать массив из 10 элементов и отсортировать его по последней цифре.
// Данные на входе: 10 целых чисел через пробел
// Этот же массив отсортированный по последней цифре
// Пример №1
// Данные на входе: 14 25 13 30 76 58 32 11 41 97
// Данные на выходе: 30 11 41 32 13 14 25 76 97 58
// Пример №2
// Данные на входе: 109 118 100 51 62 73 1007 16 4 555
// Данные на выходе: 100 51 62 73 4 555 16 1007 118 109

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

void buble_sort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if((arr[i] % 10) > (arr[j] % 10)) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(void) {
    int my_arr[SIZE];
    printf("Enter the elements for the array:\n");
    read_arr(my_arr, SIZE);
    buble_sort(my_arr, SIZE);
    print_arr(my_arr, SIZE);

    return 0;
}
