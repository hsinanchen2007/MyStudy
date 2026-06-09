### 解题思路
纯C 在矩阵里做标记

### 代码

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    // 在第一行和第一列标记, 若第一行和第一列存在0就再用bRow和bCol标记
    // 因为是从左到右，从上到下遍历矩阵，所以不用担心第一行和第一例会先受其他行列影响
    // 标记是为了置零时用的
    bool bRow = false;
    bool bCol = false;
    int row = 0;
    int col = 0;

    for (row = 0; row <= matrixSize - 1; row++)
    {
        for (col = 0; col <= *matrixColSize - 1; col++)
        {
            if (0 == matrix[row][col])
            {
                if (0 == row)
                {
                    bCol = true;
                }

                if (0 == col)
                {
                    bRow = true;
                }

                matrix[0][col] = matrix[row][0] = 0;
            }
        }
    }

    // 先置零除第一行和第一列的
    for (row = 1; row <= matrixSize - 1; row++)
    {
        for (col = 1; col <= *matrixColSize - 1; col++)
        {
            if (0 == matrix[row][0] || 0 == matrix[0][col])
            {
                matrix[row][col] = 0;
            }
        }
    }

    // 再置零第一行和第一列
    if (bRow)
    {
        for (row = 0; row <= matrixSize - 1; row++)
        {
            matrix[row][0] = 0;
        }
    }

    if (bCol)
    {
        for (col = 0; col <= *matrixColSize - 1; col++)
        {
            matrix[0][col] = 0;
        }
    }
}
```