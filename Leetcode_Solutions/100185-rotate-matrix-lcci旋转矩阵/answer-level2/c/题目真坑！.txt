### 解题思路
之前不知道M=N，一直在想矩阵的行列不同要怎么办，我服了

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize <= 1) return ;
    int i = 0, j, tmp;
    for (; i < (matrixSize >> 1); ++i)
        for (j = 0; j < (matrixSize >> 1); ++j){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = tmp;
        }
    if (matrixSize & 1)
        for (i = 0; i < (matrixSize >> 1); ++i){
            tmp = matrix[i][matrixSize >> 1];
            matrix[i][matrixSize >> 1] = matrix[matrixSize >> 1][i];
            matrix[matrixSize >> 1][i] = matrix[matrixSize - i - 1][matrixSize >> 1];
            matrix[matrixSize - i - 1][matrixSize >> 1] = matrix[matrixSize >> 1][matrixSize - i - 1];
            matrix[matrixSize >> 1][matrixSize - i - 1] = tmp;
        }
}
```