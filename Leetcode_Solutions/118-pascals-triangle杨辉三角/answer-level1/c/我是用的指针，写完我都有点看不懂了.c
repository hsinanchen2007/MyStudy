### 解题思路
我是用的指针，写完我都有点看不懂了

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i, j;

    int **parr = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    *returnSize = numRows;

    for (i = 0; i < numRows; i++)
    {
        *((*returnColumnSizes) + i) = i + 1;
        *(parr + i) = (int *)malloc(sizeof(int) * (i + 1));
        **(parr + i) = 1;
        *(*(parr + i) + i) = 1;
        j = 1;
        while (j < i)
        {
            *((*(parr + i)) + j) = *((*(parr + i - 1)) + j) + *((*(parr + i - 1)) + j - 1);
            j++;
        }
    }
    return parr;
}
```