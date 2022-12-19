### 解题思路
原地交换四个位置

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp;
    for(i = 0;i < matrixSize/ 2;i ++)
        for(j = 0;j < (matrixColSize[i] + 1) / 2;j ++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
}
```