#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle an array
void shuffle(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void createMatrix(int arr[][4])
{
    // Initialize array with numbers from 1 to 15
    int nums[15];
    for (int i = 0; i < 15; i++)
    {
        nums[i] = i + 1;
    }

    // Shuffle the array
    srand(time(0));
    shuffle(nums, 15);

    // Fill the 4x4 array with shuffled numbers

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (index < 15)
            {
                arr[i][j] = nums[index++];
            }
            else
            {
                arr[i][j] = 0; // Last element is 0
            }
        }
    }
}

// line 41
// showing matrix
void showMatrix(int arr[][4])
{
    int i, j;
   

    printf("Generated 4x4 array:\n");
    printf("------------\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("------------\n");
}



int main()
{
    int matrix[4][4];

    createMatrix(matrix);
    showMatrix(matrix);
    return 0;
  
}
