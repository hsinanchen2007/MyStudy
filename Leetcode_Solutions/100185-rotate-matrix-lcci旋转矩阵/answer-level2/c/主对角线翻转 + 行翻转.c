思路：
    分为两步：
    1）沿主主对角线将矩阵翻转，即matrix[i][j] = matrix[j][i];
    2）对举证的每一行执行一维数组翻转操作；

代码：
void RevertArr(int *arr, int size)
{
    int i, j;
    int tmp;

    for (i = 0, j = size - 1; i < j; i++, j--) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    return;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, k;
    int tmp;

    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < i; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (i = 0; i < matrixSize; i++) {
        RevertArr(matrix[i], matrixSize);
    }

    return;
}