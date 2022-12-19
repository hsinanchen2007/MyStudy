```
int compare(const void *p1, const void *p2)
{
    int *e1 = *(int **) p1;
    int *e2 = *(int **) p2;
    return e1[0] - e2[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if (intervals == NULL || intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), compare);
    int **returnValue = (int**)malloc(sizeof(int*)*intervalsSize);
    int i;
    *returnSize = 0;
    for (i = 0; i < intervalsSize-1; i++) {
        if (intervals[i+1][0] > intervals[i][1]) {
            returnValue[*returnSize] = malloc(sizeof(int)*(*intervalsColSize));           
            for (int j = 0; j < *intervalsColSize; j++) {
                returnValue[*returnSize][j] = intervals[i][j];
            }
            (*returnSize)++;
        } else {
            intervals[i+1][0] = intervals[i][0]; // 合并
            if (intervals[i+1][1] < intervals[i][1]) {
                intervals[i+1][1] = intervals[i][1];
            }
        }
    }

    returnValue[*returnSize] = malloc(sizeof(int)*(*intervalsColSize));           
    for (int j = 0; j < *intervalsColSize; j++) {
        returnValue[*returnSize][j] = intervals[i][j];
    }
    (*returnSize)++;

    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return returnValue;

}
```
