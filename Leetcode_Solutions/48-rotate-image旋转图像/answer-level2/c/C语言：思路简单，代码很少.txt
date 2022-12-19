```c
void swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    *matrixColSize = n;

    //以matrix[0][0]到matrix[n-1][n-1]的连线，中心对称两两交换
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    //左右对称两两交换，奇偶矩阵皆可以
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n / 2; j++){
            swap(&matrix[i][j], &matrix[i][n - 1 - j]);
        }
    }
}
```