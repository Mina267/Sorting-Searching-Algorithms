#include <stdbool.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>

void linear_search(int array[], int n, int target_num);
void binary_search(int array[], int n, int target_num);
int binary_search_recursion(int array[], int left, int right, int target_num);
void selection_sort(int array[], int n);
void Swap(int *a, int *b);
void buble_sort(int array[], int n);
void merge_sort(int array[], int length);
void merge_sort_recursion(int array[], int l, int r);
void merge_sorted_arrays(int array[], int l, int m, int r);




int main(){
    int array[] = {9, 3, 1, 15, 8} ;

    // Get size of array
    // sizeof(array) get size of array in bytes if array have 10 integer and one integer = 4 bytes then  sizeof(array) = 10 * 4 = 40 bytes
    // sizeof(array[0]) = 1 * 4 = 4 bytes
    // n = sizeof(array) / sizeof(array[0]) = 40 / 4 = 10 integer
    // why we use 0 index in array[0] because we do not know length of array but it has at least one element which index 0 array[0]
    int n = sizeof(array) / sizeof(array[0]);

    // Sorting
    printf("Selction sort\n");
    selection_sort(array, n);
    printf("---------------------------------------- \n");
    printf("Buble sort\n");
    buble_sort(array, n);
    printf("---------------------------------------- \n");
    printf("Merge sort\n");
    merge_sort(array, n);

    //searching
    printf("---------------------------------------- \n");
    int num;
    printf("Enter number you want to search:  ");
    scanf("%i", &num);
    printf("Linear Search:\n");
    linear_search(array, n, num);
    printf("---------------------------------------- \n");
    int num2;
    printf("Enter number you want to search:  ");
    scanf("%i", &num2);
    printf("binary Search:\n");
    binary_search(array, n, num2);
}


void linear_search(int array[], int n, int target_num){

    bool found = false;
    for(int i = 0; i < n; i++){
        if(array[i] == target_num)
        {
            printf("Found! number = %i, index = %i\n", target_num, i);
            found = true;
            break;
        }

    }
    if(!found)
    {
        printf("Not found! \n");
    }

}



void binary_search(int array[], int n, int target_num)
{
    // Call binary search recurion he left index of 0 and the right index of length - 1
    // are provided as we are initially looking  at sorting "the entire array"
    int x = binary_search_recursion(array, 0 , n - 1, target_num);

    // if recurion function return -1 means there is no number found
    if (x == -1){
        printf("Not found! \n");
    }
    else
    {
        printf("Found! number = %i, index = %i\n", target_num, x);
    }
}

int binary_search_recursion(int array[], int left, int right, int target_num)
{


    if(left <= right){
        // calculate mid point of array
        int mid = left + (right - left) / 2;
        // if mid number is middle return index of that number
        if(target_num == array[mid])
        {
            return mid;
        }
        // if number smaller than middle number
        else if (target_num < array [mid])
        {
            // search left half
            return binary_search_recursion(array, left, mid - 1, target_num);
        }
        // if number greater than middle number
        else if (target_num > array [mid])
        {
            // search right half
            return binary_search_recursion(array, mid + 1, right, target_num);
        }
    }

    // if you did not find number return -1, means there is no number found
    return -1;
}



void selection_sort(int array[], int n){

    int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++)
        {
            if(array[i] < array[j]){
              Swap(&array[i], &array[j]);
            }
        }
    }
    for(int i = 0; i < n ; i++){
    printf("%i\n",array[i]);
    }
}


void buble_sort(int array[], int n){
    bool swapped;
    for (int j = 0; j < n - 1; j++)
    {
        swapped = false;
        for(int i = 0; i < n - 1; i++)
        {
            if(array[i] > array[i + 1])
            {
                 Swap(&array[i], &array[i + 1]);
                 swapped = true;
            }
        }
        // IF no two elements were swapped by inner loop, then break
        if(swapped == false)
        {
            break;
        }
    }
    for(int i = 0; i < n ; i++){
    printf("%i\n",array[i]);
    }
}




void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



// https://www.youtube.com/watch?v=LeWuki7AQLo
// Sort function take from Main length og array and array only
void merge_sort(int array[], int length)
{

    // Call merge sort recurion he left index of 0 and the right index of length - 1
    // are provided as we are initially looking  at sorting "the entire array"
    merge_sort_recursion(array, 0, length - 1);

    for(int i = 0; i < length ; i++){
        printf("%i\n",array[i]);
    }
}



void merge_sort_recursion(int array[], int l, int r)
{

    if (l < r)
    {
        // find the midpoint of left and right of array
        int m = l + (r - l) / 2;

        // Sort left half numbers of array
        merge_sort_recursion(array, l, m);
        // Sort right half numbers of array
        merge_sort_recursion(array, m + 1, r);

        // merge sorted value
        // at this point both portions of the array have been sorted, and we now
        // merge the sorted portions of the array
        merge_sorted_arrays(array, l, m, r);
    }
}



void merge_sorted_arrays(int array[], int l, int m, int r)
{


    // calculate the length of the left and right portions of the array
    // if array has ten index = array[10] index from 0 to 9
    // So m = 4,  r = 9 and l = 0
    // left_length  = 4 - 0 + 1 = 5     ----> length of left array
    // right_length = 9 - 4 = 5         ----> length of right array
    int left_length = m - l + 1;
    int right_length = r - m;

    // create temporary arrays to store these portions
    int temp_left[left_length];
    int temp_right[right_length];

    // used as index/counter variables for the 3 arrays a, temp_left, temp_right
    int i, j, k;

    // copy the left portion into the temp_left array
    for (i = 0; i < left_length; i++)
        temp_left[i] = array[l + i];

    // copy the right portion into the temp_right array
    for (i = 0; i < right_length; i++)
        temp_right[i] = array[m + 1 + i];


    // Use i to move through the indexes of temp_left,
    // j to move through the indexes of temp_right,
    // k to move through the portion of the array to sort them

    for (i = 0, j = 0, k = l; k <= r; k++)
    {


        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            array[k] = temp_left[i];
            i++;
        }

        else
        {
            array[k] = temp_right[j];
            j++;
        }
      }
}



