### 解题思路
通过矩阵斜轴转置，然后通过中轴反转实现顺时针

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) return;
    int tmp;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < (*matrixColSize) / 2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize- j - 1];
            matrix[i][matrixSize- j - 1] = tmp;
        }
    }
}
```