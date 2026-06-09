申请变量dir作为遍历方向，循环主体为推算第i个元素对应的矩阵下标i、j的计算。
注意每种方向下的状态机转换条件，不涉及转换的直接按方向加减下标即可。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* travOrder = NULL;
    int** markMatrix = NULL;
    int idx = 0;
    int i = 0;
    int j = 0;
    int dir = RIGHT;    // 1：向右，2：向下, 3：向左，4：向上

    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    markMatrix = (int**)malloc(matrixSize * sizeof(int*));
    if (markMatrix == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < matrixSize; i++) {
        markMatrix[i] = (int*)malloc(*matrixColSize * sizeof(int));
        if (markMatrix[i] == NULL) {
            *returnSize = 0;
            goto exit;
        }

        for (j = 0; j < *matrixColSize; j++) {
            markMatrix[i][j] = 0;
        }
    }

    *returnSize = matrixSize * (*matrixColSize);
    travOrder = (int*)malloc(*returnSize * sizeof(int));
    if (travOrder == NULL) {
        *returnSize = 0;
        goto exit;
    }

    i = 0;
    j = 0;
    for (idx = 0; idx < *returnSize; idx++) {
        travOrder[idx] = matrix[i][j];
        markMatrix[i][j] = 1;

        switch (dir) {
            case RIGHT:
                if (j == (*matrixColSize - 1)) {
                    i = i + 1;
                    dir = DOWN;
                } else if (markMatrix[i][j + 1] == 1) {
                    i = i + 1;
                    dir = DOWN;
                } else {
                    j = j + 1;
                }
                break;

            case DOWN:
                if (i == (matrixSize - 1)) {
                    j = j - 1;
                    dir = LEFT;
                } else if (markMatrix[i + 1][j] == 1) {
                    j = j - 1;
                    dir = LEFT;
                } else {
                    i = i + 1;
                }
                break;

            case LEFT:
                if (j == 0) {
                    i = i - 1;
                    dir = UP;
                } else if (markMatrix[i][j - 1] == 1) {
                    i = i - 1;
                    dir = UP;
                } else {
                    j = j - 1;
                }
                break;

            default:
                if (i == 0) {
                    j = j + 1;
                    dir = RIGHT;
                } else if (markMatrix[i - 1][j] == 1) {
                    j = j + 1;
                    dir = RIGHT;
                } else {
                    i = i - 1;
                }
        }
    }

exit:
    for (i = 0; i < matrixSize; i++) {
        if (markMatrix[i] != NULL) {
            free(markMatrix[i]);
        }
    }
    free(markMatrix);

    return travOrder;
}

int main()
{
    int row1[] = { 1,  2,  3,  4};
    int row2[] = { 5,  6,  7,  8};
    int row3[] = { 9, 10, 11, 12};
    int row4[] = {13, 14, 15, 16};

    int* matrix[] = {row1, row2, row3, row4};
    int matrixSize = sizeof(matrix) / sizeof(int*);
    int colSize = sizeof(row1) / sizeof(int);
    int retSize = 0;
    int i;

    int* travOrder = spiralOrder(matrix, matrixSize, &colSize, &retSize);
    for (i = 0; i < retSize; i++) {
        printf("%d\n", travOrder[i]);
    }

    free(travOrder);

    getchar();
    return 0;
}
```

