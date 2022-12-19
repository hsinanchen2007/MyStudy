void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int i;
    int j;
    int k;
    int temp;

    if ((matrix == NULL) || (matrixSize <= 0) || (matrixColSize == NULL)) {
        return;
    }

    /* 先把行对换 */
    i = 0;
    j = matrixSize - 1;

    while (i < j) {
        for (k = 0; k < matrixColSize[i]; k++) {
            temp = matrix[i][k];
            matrix[i][k] = matrix[j][k];
            matrix[j][k] = temp;
        }

        i++;
        j--;
    }

    /* 在沿着斜对角线对换 */
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < matrixColSize[i]; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    return;
}