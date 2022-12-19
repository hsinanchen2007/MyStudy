### 解题思路
比较和操作时intervals不能按数组处理

### 代码
```c
int minMeet()
{
    return 0;
}

int cmp(void *a, void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;

    if (pa[0] == pb[0]) {
        return (pb[1] - pa[1]);
    } else {
        return pa[0] - pb[0];
    }
}

int minMeetingRooms(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (intervalsSize <= 0) {
        return 0;
    }

    if (intervalsSize == 1) {
        return 1;
    }

    int index[intervalsSize];
    for (int i = 0; i < intervalsSize; i++) {
        index[i] = 0;
    }
    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int count = 0;
    int *h = intervals[0];
    int *p = NULL;
    int *q = NULL;

    for (int i = 1; i <= intervalsSize; i++) {
        p = h;
        q = h;
        int j = 0;
        while (j < intervalsSize) {
            p = intervals[j];
            if (index[j] == 0) {
                index[j] = i;
                count++;
                break;
            }
            j++;
        }

        while (j < intervalsSize) {
            q = intervals[j];
            if (index[j] == 0 && q[0] - p[1] >= 0) {
                index[j] = i;
                p = q;
            }
            j++;
        }
    }
    return count;
}
```