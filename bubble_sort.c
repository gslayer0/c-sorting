#include <stdio.h>
#include "libs/utility/utility.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int arr_length) {
  int upper_bound = arr_length;
  for (int j = 0; j < (arr_length - 1); j++) {
    for (int i = 0; i < (upper_bound - 1); i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
      }
    }
    upper_bound--;
  }
}

int main() {
  int length = 9;
  int arr[9] = {9, 8, 5, 6, 7, 4, 3, 2, 1};

  print_arr(arr, length);
  bubble_sort(arr, length);
  print_arr(arr, length);
}
