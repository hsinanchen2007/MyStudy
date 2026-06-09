### 解题思路
1. 用第一行标记某一列是否要清零，用第一列标记某一行是否清零，[0,0]特殊处理，增加标记
2. 清零 对于matrix[0][0] 最后单独处理

### 代码

```c

// 用第一行标记某一列是否要清零，用第一列标记某一行是否清零，[0,0]特殊处理，增加标记
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    if (matrix == NULL || matrixColSize == NULL) {
        return;
    }

    // 1. 标记行列
    bool col = false;
    bool row = false;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i == 0) {
                    row = true;
                }
                if (j == 0) {
                    col = true;
                }
            }
        }
    }

    // 2. 清零 对于matrix[0][0] 最后单独处理
    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < matrixColSize[i]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            for (int k = 0; k < matrixSize; k++) {
                matrix[k][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0 && row) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }

    if (matrix[0][0] == 0 && col) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[j][0] = 0;
        }
    }
}
```