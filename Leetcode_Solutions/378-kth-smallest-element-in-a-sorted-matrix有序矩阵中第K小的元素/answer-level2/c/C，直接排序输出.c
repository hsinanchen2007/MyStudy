先把矩阵导出到数组，然后排序输出，用例也能通过，排名还挺高

int Cmp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int col = *matrixColSize;
    int *res = (int *)malloc(sizeof(int) * matrixSize * col);
    int cnt = 0;
    int i, j;
    
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < col; j++) {
            res[cnt++] = matrix[i][j];
        }
    } 

    qsort(res, matrixSize * col, sizeof(int), Cmp);

    return res[k - 1];
}