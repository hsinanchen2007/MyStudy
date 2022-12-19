### 解题思路
此处撰写解题思路

### 代码

```c
void SetZero(int** matrix, int matrixSize, int matrixColSize, int i, int j)
{
    for (int m = 0; m < matrixColSize; m++) {
        matrix[i][m] = 0;
    }
    for (int n = 0; n < matrixSize; n++) {
        matrix[n][j] = 0;
    }
}


void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    if (matrix == NULL || matrixSize <= 0 || *matrixColSize <= 0) {
        return;
    }
    int** buffer = (int**)calloc(matrixSize, sizeof(int*));
    if (buffer == NULL) {
        return;
    }
    for (int i = 0; i < matrixSize; i++) {
        buffer[i] = (int*)calloc(*matrixColSize,sizeof(int));
        if (buffer[i] == NULL) {
            return;
        }
        memcpy(buffer[i], matrix[i], sizeof(int)*(*matrixColSize));
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                SetZero(buffer, matrixSize, *matrixColSize, i, j);
            }
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        memcpy(matrix[i], buffer[i], sizeof(int)*(*matrixColSize));
        free(buffer[i]);
    }
    free(buffer);
}
```