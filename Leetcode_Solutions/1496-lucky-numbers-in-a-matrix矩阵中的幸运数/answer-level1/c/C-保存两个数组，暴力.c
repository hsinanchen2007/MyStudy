### 解题思路
保存两个数组，分别记录每一行最小的和每一列最大的。
遍历matrix，如果发现刚好符合这两个条件，则加入到结果集里。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int resSize = matrixSize <= *matrixColSize ? matrixSize : *matrixColSize;
    int *res = (int *)malloc(sizeof(int) * resSize);
    int *minInRow = (int *)malloc(sizeof(int) * matrixSize);
    int *maxInColumn = (int *)malloc(sizeof(int) *(*matrixColSize));
    *returnSize = 0;

    for (int i = 0; i < matrixSize; i++) {
        int min = 0xfffffff;
        for (int j = 0; j < (*matrixColSize); j++) {
            if (matrix[i][j] <= min) {
                min = matrix[i][j];
            }
        }
        minInRow[i] = min;
    }

    for (int j = 0; j <(*matrixColSize); j++) {
        int max = 0;
        for (int i = 0; i < matrixSize; i++) {
            if (matrix[i][j] >= max) {
                max = matrix[i][j];
            }
        }
        maxInColumn[j] = max;
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < (*matrixColSize); j++) {
            if (matrix[i][j] == minInRow[i] && matrix[i][j] == maxInColumn[j]) {
                res[(*returnSize)++] = matrix[i][j];
            }
        }
    }

    return res;
}
```