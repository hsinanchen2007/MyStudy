**简单前缀法就可以过**

int Prefix(int** matrix, int matrixSize, int matrixColSize, int k) {
    int i, j, l, m, t , left, right, row;
    int *sum;
    int result = -65535;
    int tmp;

    for (i = 0; i < matrixColSize; i++) {
        sum = (int*)malloc(sizeof(int) * matrixSize);
        memset(sum, 0, sizeof(int) * matrixSize);
        for(j = i; j < matrixColSize; j++) {
            for(l = 0; l < matrixSize; l++) {
                sum[l] += matrix[l][j];
            }
            tmp = 0;
            for(m = 0; m < matrixSize; m++) {
                tmp = sum[m];
                if(tmp <= k && tmp > result) result = tmp;
                for(t = m + 1; t < matrixSize; t++) {
                    tmp += sum[t];
                    if(tmp <= k && tmp > result) result = tmp;
                }
            }
        }
    }
    return result;
}

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int i,j;

    int result = -65535;
    int tmpResult;

    result = Prefix(matrix, matrixSize, *matrixColSize, k);

    return result;

}