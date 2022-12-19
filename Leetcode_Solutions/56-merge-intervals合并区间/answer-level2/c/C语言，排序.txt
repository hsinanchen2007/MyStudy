#define MAX(A, B) (A) > (B) ? (A) : (B)

int compare(const void **p1, const void **p2)
{
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervals == NULL || intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int **retArray;
    int retArraySize = 0;
    int tmpArray[2];
    int i;

    retArray = (int **)malloc(sizeof(int *) * intervalsSize);
    for (i = 0; i < intervalsSize; i++) {
        retArray[i] = (int *)malloc(sizeof(int) * (*intervalsColSize));
        memset(retArray[i], 0, sizeof(int) * (*intervalsColSize));
    }

    qsort(intervals, intervalsSize, sizeof(int *), compare);

    for (i = 0; i < intervalsSize; i++) {
        tmpArray[0] = intervals[i][0];
        tmpArray[1] = intervals[i][1];
        if (i + 1 < intervalsSize) {
            for (; (i + 1  < intervalsSize) && tmpArray[1] >= intervals[i + 1][0]; i++) {
                tmpArray[1] = MAX(intervals[i + 1][1], tmpArray[1]);
            }
        }
        retArray[retArraySize][0] = tmpArray[0];
        retArray[retArraySize++][1] = tmpArray[1];
    }
    *returnColumnSizes = (int *)malloc(retArraySize * sizeof(int));
    for (i = 0; i < retArraySize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = retArraySize;
    return retArray;
}