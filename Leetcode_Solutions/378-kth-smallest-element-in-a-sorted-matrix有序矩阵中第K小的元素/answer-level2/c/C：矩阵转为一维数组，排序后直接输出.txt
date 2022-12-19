思路：
按下标将矩阵转化为一维数组，qsort排序后直接输出第k小的元素
```
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int row = matrixSize;
    int col = *matrixColSize;
    int array[row * col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            array[i * col + j] = matrix[i][j];
        }
    }
    qsort(array, row * col, sizeof(int), compare);
    return array[k-1];
}
```
