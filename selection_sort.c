#include <stdio.h>
#include "libs/utility/utility.h"

void selection_sort(int arr[], int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    int *curr_minimum = &arr[i];
    for (int j = i; j < arr_length; j++) {
      if (*curr_minimum > arr[j]) {
        curr_minimum = &arr[j];
      }
    }
    if (arr[i] > *curr_minimum) {
      int tmp = arr[i];
      arr[i] = *curr_minimum;
      *curr_minimum = tmp;
    }
  }
}

int main() {

  int arr_length = 9;
  int arr[9] = {9, 8, 5, 6, 7, 4, 3, 2, 1};

  print_arr(arr, arr_length);
  selection_sort(arr, arr_length);
  print_arr(arr, arr_length);
}
