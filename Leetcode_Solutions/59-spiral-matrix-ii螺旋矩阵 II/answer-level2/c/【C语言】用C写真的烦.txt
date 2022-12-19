处理这个returnColumnSizes 一定要注意呀，这玩意还需要自己申请空间的。
传一个** 的指针，还不太会处理。

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    }
    int num = 1;
    int** res = (int**)malloc(sizeof(int*) * n);
    returnColumnSizes[0] = (int*)malloc(n * sizeof(int));
    if (res == NULL) {
        return res;
    }
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        returnColumnSizes[0][i] = n;
        if (res[i] == NULL) {
            return res;
        }
    }    
    for (int i = 0; i < n / 2; i++) {
        int row = i;
        int col = i;
        for (int j = 0; j < n - (1 + 2 * i);j++) {
            res[row][col++] = num++;
        }
        for (int j = 0; j < n - (1 + 2 * i);j++) {
            res[row++][col] = num++;
        }
        for (int j = 0; j < n - (1 + 2 * i);j++) {        
            res[row][col--] = num++;
        }
        for (int j = 0; j < n - (1 + 2 * i);j++) {
            res[row--][col] = num++;
        }
    }
    if (n % 2 == 1) {
        res[n / 2][n / 2] = n * n;
    }
    *returnSize = n;
    return res;
}

```