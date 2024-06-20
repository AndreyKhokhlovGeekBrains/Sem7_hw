// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
// Данные на входе: 12 целых чисел через пробел
// Данные на выходе: 12 целых чисел через пробел
// Пример №1
// Данные на входе: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
// Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
// Пример №2
// Данные на входе: 1 2 3 4 5 6 7 8 9 10 11 12
// Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8

#include <stdio.h>

enum {
    SIZE = 12, 
    ELEMENTS_TO_ROTATE = 4
    };

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
        printf("Invalid input. Enter a valid integer for the array:\n");
    }
    
    arr[SIZE - size] = n;
    read_arr(arr, --size);
}

void rotate_right(int *arr, int size, int elements_to_rotate) {
    int new_arr[size];

    // Copy the last elements to the beginning of new_arr
    int index_1 = size - elements_to_rotate;
    for(int i = 0; i < elements_to_rotate; i++) {
        new_arr[i] = arr[index_1++];
    }
    
    // Copy the remaining elements to new_arr
    int index_2 = 0;
    for(int i = elements_to_rotate; i < size; i++) {
        new_arr[i] = arr[index_2++];
    }

    // Copy new_arr back to the original array
    for(int i = 0; i < size; i++) {
        arr[i] = new_arr[i];
    }
}

int main(void) {
    int my_arr[SIZE];
    printf("Enter the elements for the array:\n");
    read_arr(my_arr, SIZE);
    rotate_right(my_arr, SIZE, ELEMENTS_TO_ROTATE);
    print_arr(my_arr, SIZE);

    return 0;
}
