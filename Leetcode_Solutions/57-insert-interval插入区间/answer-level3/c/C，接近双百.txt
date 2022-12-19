### 解题思路
一次通过，纪念一下

### 代码

```c
#define RES_COL_SIZE 2
#define INVALID_INTERVAL 0xFFFFFFFF

int* AddResCol(int size)
{
    int *col = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        col[i] = RES_COL_SIZE;
    }
    return col;
}

int * AddRes(int start, int end)
{
    int *p = (int*)malloc(sizeof(int) * RES_COL_SIZE);
    p[0] = start;
    p[1] = end;
    return p;
}

int MIN(int a, int b)
{
    return a > b ? b : a;
}

int MAX(int a, int b)
{
    return a < b ? b : a;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **res = NULL;

    if ((intervals == NULL) || (intervalsSize == 0)) {
        res = (int**)malloc(sizeof(int*));
        res[0] = newInterval;
        *returnSize = 1;
        *returnColumnSizes = AddResCol(1);
        return res;
    }

    if ((newInterval == NULL) || (newIntervalSize == 0)) {
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }

    res = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    memset(res, 0, sizeof(int*) * (intervalsSize + 1));
    int size = 0;

    int i;
    int start = INVALID_INTERVAL;
    int end = INVALID_INTERVAL;
    for (i = 0; i < intervalsSize; i++) {
        if (start == INVALID_INTERVAL) {
            if (intervals[i][0] > newInterval[1]) {
                res[size] = AddRes(newInterval[0], newInterval[1]);
                size++;
                break;
            } else if (intervals[i][1] < newInterval[0]) {
                res[size] = AddRes(intervals[i][0], intervals[i][1]);
                size++;
            } else {
                start = MIN(intervals[i][0], newInterval[0]);
                end = MAX(intervals[i][1], newInterval[1]);
            }
        } else {
            if (intervals[i][0] <= end) {
                start = MIN(intervals[i][0], start);
                end = MAX(intervals[i][1], end);
            } else {
                res[size] = AddRes(start, end);
                size++;
                break;
            }
        }

        if (i == intervalsSize - 1) {
            if (start == INVALID_INTERVAL) {
                res[size] = AddRes(newInterval[0], newInterval[1]);
            } else {
                res[size] = AddRes(start, end);
            }
            size++;
        }
    }

    while (i < intervalsSize) {
        res[size] = AddRes(intervals[i][0], intervals[i][1]);
        size++;
        i++;
    }

    *returnSize = size;
    *returnColumnSizes = AddResCol(size);
    return res;
}
```