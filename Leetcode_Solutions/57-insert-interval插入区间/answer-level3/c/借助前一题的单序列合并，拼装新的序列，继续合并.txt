```
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define COLUMNSIZE 2

int MergeCmp(const void *p1, const void *p2)
{
    int **d1 = (int **)p1;
    int **d2 = (int **)p2;

    if (d1[0][0] == d2[0][0]) {
        return d1[0][1] - d2[0][1];
    }

    return d1[0][0] - d2[0][0];
}

void _merge(int** intervals, int intervalsSize, int* intervalsColSize, int** res, int *returnSize)
{
    int cnt = *returnSize;
    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        while (i < intervalsSize - 1 && end >= intervals[i + 1][0]) {
            i++;
            end = MAX(end, intervals[i][1]);
        }
        res[cnt][0] = start;
        res[cnt][1] = end;
        cnt++;
    }

    *returnSize = cnt;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int **res = (int **)malloc(sizeof(int *) * intervalsSize);
    if (intervalsSize == 0) {
        *returnSize = 0;
        return res;
    }

    qsort(intervals, intervalsSize, sizeof(intervals[0]), MergeCmp);
    for (int i = 0; i < intervalsSize; i++) {
        res[i] = (int *)malloc(sizeof(int) * intervalsColSize[i]);
        memset(res[i], 0, sizeof(int) * intervalsColSize[i]);
    }

    *returnSize = 0;
    _merge(intervals, intervalsSize, intervalsColSize, res, returnSize);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = COLUMNSIZE;
    }

    return res;
}

void NewNode(int **ans, int start, int end, int *returnSize, int *returnColumnSize)
{
    int *node = (int *)malloc(sizeof(int) * COLUMNSIZE);
    node[0] = start;
    node[1] = end;
    ans[*returnSize] = node;
    returnColumnSize[*returnSize] = COLUMNSIZE;
    (*returnSize)++;
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    /* add newinterval to the new space*/
    int **newIntervals = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
    int *newIntervalColSize = (int *)malloc(sizeof(int) * (intervalsSize + 1));
    for (int i = 0; i < intervalsSize + 1; i++) {
        *newIntervals = (int *)malloc(sizeof(int) * COLUMNSIZE);
        memset(*newIntervals, 0, sizeof(int) * COLUMNSIZE);
        newIntervalColSize[i] = COLUMNSIZE;
    }

    *returnSize = 0;
    *returnColumnSizes = newIntervalColSize;
    
    /* connect the intervals and the new interval */
    for (int i = 0; i < intervalsSize; i++) {
        NewNode(newIntervals, intervals[i][0], intervals[i][1], returnSize, newIntervalColSize);
    }
    NewNode(newIntervals, newInterval[0], newInterval[1], returnSize, newIntervalColSize);

    /* merge the space and return */
    return merge(newIntervals, intervalsSize + 1,  newIntervalColSize, returnSize, returnColumnSizes);
}
```
