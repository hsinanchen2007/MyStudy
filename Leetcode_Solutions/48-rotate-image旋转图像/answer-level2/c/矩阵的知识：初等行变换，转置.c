### 解题思路
题目要求将矩阵顺时针旋转90°，通过观察，可以先对矩阵进行行变换，即对一个n*n矩阵，互换它的第i行和第n-i行(其中，0<=i<n)，再将进行了行变换的矩阵，转置，即实现了顺时针旋转90°的目的。

### 代码

```c
void exchangeRow(int** matrix, int matrixSize)//将矩阵的第i行和第matrixSize-i行互换(0<=i<matrixSize)
{
    int *tmp = malloc(sizeof(int) * matrixSize);
    for(int i = 0, j = matrixSize-1; i < j; ++i, --j) {
        tmp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = tmp;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    exchangeRow(matrix,matrixSize);
    for(int i = 0; i < matrixSize; ++i)//转置
        for(int j = i; j < matrixSize; ++j){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
}
```