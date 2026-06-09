提供一个O(1)空间的题解，简单描述思路是扫描每一行，如果存在零的话，先将该行非零元素设置为0。相应的0元素位置设置为1，用来记录该元素列应该全部设置为0，但是暂时不对列置零。等到全部扫描完毕，把记录需要置零的列都置为0。因为使用了前面有零的行记录信息，所以不需要额外空间。
```
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, k;
    int rRow = -1;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                for (k = 0; k < matrixColSize[i]; k++) {
                    if (matrix[i][k] == 0) {
                        matrix[i][k] = 1;
                    } else {
                        matrix[i][k] = 0;
                    }
                }
                if (rRow != -1) {
                    for (k = 0; k < matrixColSize[rRow]; k++) {
                        matrix[i][k] = matrix[rRow][k] | matrix[i][k];
                        matrix[rRow][k] = 0;
                    }
                }
                rRow = i;
                break;
            }
        }
    }
    if (rRow != -1) {
        for (j = 0; j < matrixColSize[rRow]; j++) {
            if (matrix[rRow][j] == 1) {
                for (k = 0; k < matrixSize; k++) {
                    matrix[k][j] = 0;
                }
            }
        }
    }
}
```