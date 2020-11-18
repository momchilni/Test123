#include <stdio.h>
#include <stdlib.h>

int findAdjacent(int [4][4], int, int, int, int);

int main(void)
{
    int arr[4][4] = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };
    int i = 2, j = 2;
    int sum = findAdjacent(arr, i, j, 4, 4);
    printf("Adjacent cells from (%d, %d) with value 1 : %d\n", i, j, sum);
    return EXIT_SUCCESS;
}

int findAdjacent(int arr[4][4], int i, int j, int rows, int columns)
{
    int sum = 0, k = 0;
    int x = -1, y = -1; // Location of the new CELL, which
                        // we will find after adding offsets
                        // to the present value of i and j
    int offset[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    for (k = 0; k < 8; k++)
    {
        x = i + offset[k][0];
        y = j + offset[k][1];
        if (isValidCell(x, y, rows, columns))
        {
            if (arr[x][y] == 1)
                sum += 1;
        }
    }

    return sum;
}

int isValidCell(int x, int y, int rows, int columns)
{
    if ((x >= 0 && x < rows) && (y >= 0 && y < columns))
        return 1;
    return 0;
}
