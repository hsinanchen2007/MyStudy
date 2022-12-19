### 解题思路
上代码

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i< matrixSize / 2; i++) {
        for (int j = i; j < matrixSize - 1 - i; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
    }
}
```