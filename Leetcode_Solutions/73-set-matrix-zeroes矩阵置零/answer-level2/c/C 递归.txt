大体思路是通过递归的方式滞后置0操作，代码如下：
```
void searchZero(int** matrix, int id, int jd, int matrixSize, int matrixColSize)
{
    int index;

    for (int i = id; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == 0) {

                matrix[i][j] = -1;
                searchZero(matrix, i, j, matrixSize, matrixColSize);

                for (index = 0; index < matrixSize; index++) {
                    matrix[index][j] = 0;
                }

                for (index = 0; index < matrixColSize; index++) {
                    matrix[i][index] = 0;
                }

                return;
            }
        }
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{

    if (matrixSize == 0) {
        return NULL;
    }

    searchZero(matrix, 0, 0, matrixSize, matrixColSize[0]);
}
```
