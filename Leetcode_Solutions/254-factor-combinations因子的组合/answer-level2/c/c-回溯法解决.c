### 解题思路
此处撰写解题思路
1. 因子都是从 2 开始， 最大应该是 n/2.
2. i = {2,3,...,n/2}, 依次尝试，如果， n%i == 0, 

### 代码

```c
int ret[2024][2024], totalSize = 0;
int totalColSize[2024];
int cur_ret_col;

void getFactor(int n, int factor, int from_index){
    int cur_ret_col;
    int i, j;

    if (from_index >= 0 && ret[from_index][totalColSize[from_index] - 1] > n) {
        /* 目前队列中的已经比 需要拆分的大了，没有必要了 */
        return;
    }

    for (i = factor; i <= n/factor; i++) {
        if(n%i == 0 && i <= n/i) {
            /* 可以输出了 */
            if (from_index != -1)
                cur_ret_col = totalColSize[from_index];
            else
                cur_ret_col = 1;
            /* 先把全面的补上 */
            for (j = 0; j < cur_ret_col - 1; j++) {
                ret[totalSize][j] = ret[from_index][j];
            }
            ret[totalSize][cur_ret_col - 1] = i;
            ret[totalSize][cur_ret_col++] = n/i;
            totalColSize[totalSize] = cur_ret_col;
            totalSize++;

            getFactor(n/i, i, totalSize - 1);
        }
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** getFactors(int n, int* returnSize, int** returnColumnSizes){
    int i, j;
    int **result;

    totalSize = 0;
    getFactor(n, 2, -1);

    result = (int **)malloc(sizeof(int *) * (totalSize + 1));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (totalSize + 1));
    *returnSize = totalSize;

    for (i = 0; i < totalSize; i++) {
        (*returnColumnSizes)[i] = totalColSize[i];
        result[i] = (int *)malloc(sizeof(int) * (totalColSize[i] + 1));
        for (j = 0; j < totalColSize[i]; j++)
        {
            result[i][j] = ret[i][j];
        }
    }

    return result;
}


```