### 解题思路
此处撰写解题思路

### 代码

```c
//(r1, c1) (r2, c2)满足对角线的特点 r1 - c1 == r2 - c2
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) {
        return false;
    }

    int i = 0;
    int j = 0;
    for (; i < matrixSize; i++) {
        for (j = i + 1; j < matrixSize; j++) {
            if (j - i < matrixColSize[i + 1]) {
                if (matrix[i][0] != matrix[j][j - i]) {
                    return false;
                }
            }
        }
    }

    i = 0;
    j = 0;
    for (; j < matrixColSize[0]; j++) {
        for (i = j + 1; i < matrixColSize[0]; i++) {
            if (i - j < matrixSize) {
                if (matrix[0][j] != matrix[i-j][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}
```