#include <stdio.h>
#include "libs/utility/utility.h"


void merge_sort(int arr[], int left, int right)
{
    // base case: array with one element
    if (left == right)
    {
        return;
    }

    // merge_sort sub array left and right
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    int left_arr_size = mid - left + 1;
    int left_arr[left_arr_size];
    for (int i = left; i < mid + 1; i++)
    {
        left_arr[(i - left)] = arr[i];
    }

    int right_arr_size = right - mid;
    int right_arr[right_arr_size];
    for (int i = (mid + 1); i < right + 1; i++)
    {
        right_arr[(i - (mid + 1))] = arr[i];
    }

    int arr_idx = left;
    int left_idx = 0;
    int right_idx = 0;
    while (1)
    {
        if (left_arr[left_idx] < right_arr[right_idx])
        {
            arr[arr_idx] = left_arr[left_idx];
            left_idx++;
            arr_idx++;
        }
        else
        {
            arr[arr_idx] = right_arr[right_idx];
            right_idx++;
            arr_idx++;
        }
        if ((left_idx == left_arr_size) || (right_idx == right_arr_size))
        {
            break;
        }
    }

    if (left_idx == left_arr_size)
    {
        // push right
        for (int i = right_idx; i < right_arr_size; i++)
        {
            arr[arr_idx] = right_arr[i];
            arr_idx++;
        }
    }
    else
    {
        // push left
        for (int i = left_idx; i < left_arr_size; i++)
        {
            arr[arr_idx] = left_arr[i];
            arr_idx++;
        }
    }
    return;
}

int main()
{
    int arr[] = {9, 8, 7, 11, 2, 3, 4};
    print_arr(arr, 7);
    merge_sort(arr, 0, 6);
    print_arr(arr, 7);
}
