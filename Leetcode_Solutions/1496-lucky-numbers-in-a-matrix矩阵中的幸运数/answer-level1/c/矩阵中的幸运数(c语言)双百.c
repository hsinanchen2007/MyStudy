```
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int*) * matrixSize);
    int index = 0;
    for (int i = 0; i < matrixSize; i++) {
        int min = 100000;
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        for (int j = 0; j < matrixColSize[i]; j++) {
            int flag = 0;
            if (min == matrix[i][j]) {
                for (int t = 0; t < matrixSize; t++) {
                    if (matrix[t][j] > min) {
                        flag++;
                        break;
                    }
                }
                if (flag == 0) {
                    ret[index++] = min;
                }
                break;
            }
        }
    }
    *returnSize = index;
    return ret;
}
```
