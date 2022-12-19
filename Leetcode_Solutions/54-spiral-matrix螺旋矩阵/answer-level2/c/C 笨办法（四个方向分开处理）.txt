### 解题思路
可以将遍历的情况分为向右、向下、向左、向上四种情况，每次到达边界给下边界执行加一操作，上边界执行减一操作，一直循环直到把数组完全遍历

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int row = 0;
    int col = 0;
    int status = 0;
    int max_col = *matrixColSize;
    int min_col = -1;
    int max_row = matrixSize;
    int min_row = 0;
    
    if(matrixSize==0)
    {
        *returnSize=0;
        return NULL;
    }
    *returnSize = matrixSize * (*matrixColSize);
    
    int *returnMatrix = (int*)malloc((*returnSize)*(sizeof(int)));
    
    for(int k = 0; k < *returnSize ; k++)
    {
        switch(status)
        {
            case 0:                     //向右
                if(col < max_col)
                {
                    returnMatrix[k] = matrix[row][col];
                    col++;
                }
                else
                {
                    max_col--;
                    returnMatrix[k] = matrix[++row][--col];
                    row++;
                    status = 1;
                }
                break;
            case 1:                     //向下
                if(row < max_row)
                {
                    returnMatrix[k] = matrix[row][col];
                    row++;
                }
                else
                {
                    max_row--;
                    returnMatrix[k] = matrix[--row][--col];
                    col--;
                    status = 2;
                }
                break;
            case 2:                     //向左
                if(col > min_col)
                {
                    returnMatrix[k] = matrix[row][col];
                    col--;
                }
                else
                {
                    min_col++;
                    returnMatrix[k] = matrix[--row][++col];
                    row--;
                    status = 3;
                }
                break; 
            case 3:                     //向上
                if(row > min_row)
                {
                    returnMatrix[k] = matrix[row][col];
                    row--;
                }
                else
                {
                    min_row++;
                    returnMatrix[k] = matrix[++row][++col];
                    col++;
                    status = 0;
                }
                break;
        }
    }
    return returnMatrix;
}


```