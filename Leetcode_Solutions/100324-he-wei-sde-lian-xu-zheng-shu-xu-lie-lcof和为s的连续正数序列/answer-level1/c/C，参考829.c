```
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int count = 0;
    int MAXN = (int)sqrt(2.0 * target - 0.25); // 确定最大可能的连续值
    int SQUARE = MAXN * (MAXN + 1) / 2;
    int **res = (int**)malloc(MAXN * sizeof(int*));
    int *col = (int*)malloc(MAXN * sizeof(int));
    if (target <= SQUARE) SQUARE -= MAXN--; // 连续和大于目标值时减一
    while(MAXN > 0) {
        if ((target - SQUARE) % (MAXN + 1) == 0) {   
            int *tmp = (int *)malloc((MAXN + 1) * sizeof(int));        
            for (int j = 0; j < MAXN + 1; j++) {
                *(tmp + j) = (target - SQUARE) / (MAXN + 1) + j;
            }
            *(res + count) = tmp;
            *(col + count) = MAXN + 1;
            count++;
        }
        SQUARE -= MAXN--;
    }
    *returnSize = count;
    *returnColumnSizes = col;
    return res;
}
```
