思路：
顺时针旋转：先按主对角线转置，再按行翻转
逆时针旋转：先按主对角线转置，再按列翻转
注意处理下标和交换
```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 -j] = temp;
        }
    }
    return;
}
```
