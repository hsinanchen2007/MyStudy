### 解题思路
如注释！

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    /* 建议对所有的输入进行初始化输出，然后在最后正确返回的时候进行赋值。 */
    *returnSize = 0;
    *returnColumnSizes = NULL;
    // 针对特殊个数0
    if (!numRows) {
        return NULL;
    }
    
    // 申请返回内存
    int** result = (int**)malloc(numRows * sizeof(int*));
    if (!result) {
        return NULL;
    }

    int* resultColumnSizes = (int*)malloc(numRows * sizeof(int));
    if (!resultColumnSizes) {
        free(result);
        return NULL;
    }

    int i;
    for (i = 0; i < numRows; i++) {
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        if (!result[i]) {
            break;
        }
        resultColumnSizes[i] = i + 1;
        result[i][0] = 1;
        result[i][resultColumnSizes[i] - 1] = 1;
    }

    // 申请内存出错，释放所有申请的内存
    if (i < numRows) {
        i--;
        while (i >= 0) {
            free(result[i]);
            i--;
        }
        free(result);
        free(resultColumnSizes);
        return NULL;
    }

    // 实现杨辉三角
    int j;
    for (i = 2; i < numRows; i++) {
        for (j = 1; j < resultColumnSizes[i] - 1; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = resultColumnSizes;
    return result;
}
```