void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL || matrixSize != (*matrixColSize) || matrixSize <= 1) {
        return;
    }

    int i = 0; 
    int *arr = (int *)malloc(sizeof(int) * matrixSize);
    if (arr == NULL) {
        return;
    }
    while (i < (matrixSize + 1) / 2) {
        int j, k, tmp;
        int m = 0;
        // 向右 记录
        j = i;
        for (k = i; k < matrixSize - i - 1; k++) { // j = i, k = i
            arr[m] = matrix[j][k];
            m++;
        }

        // 向下 记录+赋值
        m = 0;
        for (; j < matrixSize - i - 1; j++) { // j = i, k = matrixSize - 1 - i
            tmp = matrix[j][k];
            matrix[j][k] = arr[m];
            arr[m] = tmp;
            m++;
        }

        // 向左 记录+赋值
        m = 0;
        for (; k > i; k--) { //j = matrixSize - 1 - i, k = matrixSize - 1 - i
            tmp = matrix[j][k];
            matrix[j][k] = arr[m];
            arr[m] = tmp;
            m++;
        }

        // 向上 记录+赋值
        m = 0;
        for (; j > i; j--) { //j = matrixSize - 1 - i, k = i
            tmp = matrix[j][k];
            matrix[j][k] = arr[m];
            arr[m] = tmp;
            m++;
        }

        // 向右 赋值
        m = 0;
        for (; k < matrixSize - i - 1; k++) { //j = i, k = i
            matrix[j][k] = arr[m];
            m++;
        }

        i++;
    }

    free(arr);
    return;
}