```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define UP     (1)
 #define RIGHT  (2)
 #define BOTTOM (3)
 #define LEFT   (4)

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

if(0 == matrixSize)
{
    *returnSize = 0;
    return NULL;
}

int up_bound = 0;
int left_bound = 0;
int right_bound = *matrixColSize;
int bottom_bound = matrixSize;
int count = 0;

int status = UP;
int row = 0;
int col = 0;

int *retMat = (int *)malloc(matrixSize * *matrixColSize * sizeof(int));

bool flag = true;
while(flag)
{   
    switch(status)
    {
        case UP:
        if(count == *matrixColSize * matrixSize)
        {
            flag = false;
            break;
        }
        row = up_bound;
        for(col = left_bound; col < right_bound; col++)
        {
            retMat[count] = matrix[row][col];
            count++;
        }

        up_bound++;
        status = RIGHT;
        break;

        case RIGHT:
        if(count == *matrixColSize * matrixSize)
        {
            flag = false;
            break;
        }
        col = right_bound - 1;
        for(row = up_bound; row < bottom_bound; row++)
        {
            retMat[count] = matrix[row][col];
            count++;
        }

        right_bound--;
        status = BOTTOM;
        break;

        case BOTTOM:
        if(count == *matrixColSize * matrixSize)
        {
            flag = false;
            break;
        }
        row = bottom_bound - 1;
        for(col = right_bound - 1; col >= left_bound; col--)
        {
            retMat[count] = matrix[row][col];
            count++;
        }

        bottom_bound--;
        status = LEFT;
        break;

        case LEFT:
        if(count == *matrixColSize * matrixSize)
        {
            flag = false;
            break;
        }
        col = left_bound;
        for(row = bottom_bound - 1; row >= up_bound; row--)
        {
            retMat[count] = matrix[row][col];
            count++;
        }
        left_bound++;
        status = UP;
        break;

        default:
        break;
    }
}

*returnSize = count;
return retMat;
}
```
