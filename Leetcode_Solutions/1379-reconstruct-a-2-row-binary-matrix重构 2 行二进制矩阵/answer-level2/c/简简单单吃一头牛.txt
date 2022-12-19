```
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes)
{
    int **res = malloc(2 * sizeof(int *));
    res[0] = malloc(colsumSize * sizeof(int));
    memset(res[0], 0, colsumSize * sizeof(int));
    res[1] = malloc(colsumSize * sizeof(int));
    memset(res[1], 0, colsumSize * sizeof(int));
    *returnColumnSizes = malloc(2 * sizeof(int *));
    int total1 = 0, total2 = 0;

    for (int i = 0; i < colsumSize; i++) {
        if (colsum[i] == 2) {
            res[0][i] = 1;
            res[1][i] = 1;
            total1++;
            total2++;
        }
    }
    if (total1 > upper || total2 > lower) {
        goto KO;
    }
    for (int i = 0; i < colsumSize; i++) {   
        if (colsum[i] == 1) {
            if (total1 < upper) {
                res[0][i] = 1;
                total1++;
                // printf("upper=%d, total1=%d\n", upper, total1);
            } else if (total2 < lower){
                res[1][i] = 1;
                total2++;
            } else {
                goto KO;
            }
        }
    }
    if (total1 != upper || total2 != lower) {
        goto KO;
    }    
    *returnSize = 2;
    (*returnColumnSizes)[0] = colsumSize;
    (*returnColumnSizes)[1] = colsumSize;
    return res;
KO:    
    *returnSize = 0;
    (*returnColumnSizes)[0] = 0;
    (*returnColumnSizes)[1] = 0;
    return NULL;
}
```
