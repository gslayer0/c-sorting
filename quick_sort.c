#include <stdio.h>
#include "libs/utility/utility.h"

void quick_sort(int *arr, int low, int high)
{
    if (low == high)
        return;
    int left = low;
    int right = high;
    int pivot = left;

    while (left != right)
    {
        if (pivot == left)
        {
            if (arr[pivot] > arr[right])
            {
                int tmp = arr[pivot];
                arr[pivot] = arr[right];
                arr[right] = tmp;
                pivot = right;
            }
            else
            {
                right--;
            }
        }
        else
        {
            if (arr[pivot] < arr[left])
            {
                int tmp = arr[pivot];
                arr[pivot] = arr[left];
                arr[left] = tmp;
                pivot = left;
            }
            else
            {
                left++;
            }
        }
    }
    if (pivot > low)
    {
        quick_sort(arr, low, pivot - 1);
    }
    if (pivot < high)
    {
        quick_sort(arr, pivot + 1, high);
    }
    return;
}

int main()
{
    int arr[7] = {6, 5, 4, 3, 2, 1, 0};
    print_arr(arr, 7);
    quick_sort(arr, 0, 6);
    print_arr(arr, 7);
}