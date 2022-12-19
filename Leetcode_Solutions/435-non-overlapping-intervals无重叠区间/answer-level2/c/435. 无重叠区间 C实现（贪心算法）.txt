### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(const void* a, const void* b)
{
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if (!intervals || intervalsSize <= 0) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int*), Compare);
    int cnt = 0;
    int* p = intervals[0];
    for (int i = 1; i < intervalsSize; i++) {
        if (p[1] > intervals[i][0]) {
            if (intervals[i][1] <= p[1]) {
                p = intervals[i];
                cnt++;
            } else {
                cnt++;
            }
        } else {
            p = intervals[i];
        }
    }
    return cnt;
}
```