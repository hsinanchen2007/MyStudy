### 解题思路
此处撰写解题思路
1、主要确定清楚杨辉三角的定义就好

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){ 
    int i = 0, j = 0;
    int **results = (int **)malloc(numRows * sizeof(int *));;

    *returnColumnSizes=malloc(numRows*sizeof(int));

    for(j = 0; j < numRows; j ++)
    {
        (*returnColumnSizes)[j] = j + 1;

        results[j] = (int *)malloc(sizeof(int) * (j + 1));  
        results[j][0] = 1;
        results[j][j] = 1;

        for(i = 1; i < j; i++)
        {
            results[j][i] = results[j - 1][i - 1] + results[j - 1][i];
        } 
    }

    *returnSize = numRows;

    return results;
}
```