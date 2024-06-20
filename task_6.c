// Задача 6. Чаще других
// Дан массив из 10 элементов. Определить, какое число в массиве встречается
// чаще всего. Гарантируется, что такое число ровно 1.
// Данные на входе: 10 целых числе через пробел
// Данные на выходе: Одно число, которое встречается чаще других.
// Пример
// Данные на входе: 4 1 2 1 11 2 34 11 0 11
// Данные на выходе: 11

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

int most_common_num(int *arr, int size) {
    int my_num;
    int result_count = 0;
    for(int i = 0; i < size - 1; i++) {
        int count = 0;
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]) {
                count++;
            }
            if(result_count < count) {
                my_num = arr[i];
                result_count = count;
            }
        }
    }
    return my_num;
}

int main(void) {
    int my_arr[SIZE];
    printf("Enter the elements for the array:\n");
    read_arr(my_arr, SIZE);
    printf("%d", most_common_num(my_arr, SIZE));

    return 0;
}
