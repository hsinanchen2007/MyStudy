### 解题思路
纯C

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int row = 0;
    int col = 0;
    int** ppRes = (int**)malloc(numRows * sizeof(int*));
    for (row = 0; row <= numRows - 1; row++)
    {
        ppRes[row] = (int*)malloc(numRows * sizeof(int));
    }

    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (row = 0; row <= numRows - 1; row++)
    {
        for (col = 0; col <= row; col++)
        {
            if (0 == col || row == col)
            {
                ppRes[row][col] = 1;
            }
            else
            {
                ppRes[row][col] = ppRes[row - 1][col - 1] + ppRes[row - 1][col];
            }
        }

        (*returnColumnSizes)[row] = row + 1;
    }
    
    return ppRes;
}
```