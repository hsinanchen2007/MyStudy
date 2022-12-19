### 解题思路
此处撰写解题思路

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int center = matrixSize / 2;
    int jLim = (matrixSize - 1) / 2;
    for (int i = 0; i < center; ++i) {
        for (int j = 0; j <= jLim; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - j][i];
            matrix[matrixSize - 1 - j][i] = matrix[matrixSize - 1 - i][matrixSize - 1 - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - j] = matrix[j][matrixSize - 1 - i];
            matrix[j][matrixSize - 1 - i] = temp;
        }
    }
    return;
}
```