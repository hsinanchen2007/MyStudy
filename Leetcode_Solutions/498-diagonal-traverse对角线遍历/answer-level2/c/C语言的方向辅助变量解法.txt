申请一个变量dir保存遍历方向。
循环主体为推算第i个元素对应的矩阵下标i、j的计算。
1、向上的方向：预期行标i减一，列标j加一
   需特殊处理的情况：
   1）第0行，行标i不变，列标j加一，方向发生改变；
   2）最后一列，行标i加一，列标不变，方向发生改变；

2、向下的方向：预期行标i加一，列标j减一
   需特殊处理的情况：
   1）最后一行，行标i不变，列标j加一，方向发生改变；
   2）第0列，行标i加一，列标不变，方向发生改变；

```
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* travOrder = NULL;
    int idx = 0;
    int i = 0;
    int j = 0;
    int dir = 0;    // 0：向上，1：向下

    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    if (matrixSize > 10000 || *matrixColSize > 10000) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * (*matrixColSize);
    travOrder = (int*)malloc(*returnSize * sizeof(int));
    if (travOrder == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (idx = 0; idx < *returnSize; idx++) {
        travOrder[idx] = matrix[i][j];
        if (dir == 0) {
            if (j == (*matrixColSize - 1)) {
                i = i + 1;
                dir = 1;
                continue;
            }

            if (i == 0) {
                j = j + 1;
                dir = 1;
                continue;
            }

            i = i - 1;
            j = j + 1;
        } else {
            if (i == (matrixSize - 1)) {
                j = j + 1;
                dir = 0;
                continue;
            }

            if (j == 0) {
                i = i + 1;
                dir = 0;
                continue;
            }

            j = j - 1;
            i = i + 1;
        }
    }

    return travOrder;
}
```
