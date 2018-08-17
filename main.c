#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ARR(arr) sizeof(arr)/sizeof(arr[0])

void merge(int arr1[], int len1, int arr2[], int len2)
{
    int i = len1 - 1, j = len2 - 1, k = len1 + len2 - 1;

    while (i >= 0 && j >= 0) {
        if (arr1[i] >= arr2[j])
            arr1[k--] = arr1[i--];
        else
            arr1[k--] = arr2[j--];
    }
    while (j >= 0)
        arr1[k--] = arr2[j--];
}

static void merge_three_arr(int pa[], int len, int a1[], int l1, int a2[], int l2, int a3[], int l3)
{
    (void)memcpy(pa, a1, sizeof(int) * l1);
    merge(pa, l1, a2, l2);
    merge(pa, l1 + l2, a3, l3);
}

void show_arr(const int arr[], const int len)
{
    int i = 0;

    for(; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}   

int main(void)
{
    int arr1[] = {2, 4, 6, 8, 28, 48, 100, 1111};
    int arr2[] = {0, 1, 1,1, 1, 1, 3, 5, 7, 15};
    int arr3[] = {-6, -1, 10, 11};
    int len_parr= SIZE_ARR(arr1) + SIZE_ARR(arr2) + SIZE_ARR(arr3);
    int parr[len_parr];

    show_arr(arr1, SIZE_ARR(arr1));
    show_arr(arr2, SIZE_ARR(arr2));
    show_arr(arr3, SIZE_ARR(arr3));
    merge_three_arr(parr, len_parr, arr1, SIZE_ARR(arr1), arr2, SIZE_ARR(arr2), arr3, SIZE_ARR(arr3));
    show_arr(parr, len_parr);

    return 0;
}