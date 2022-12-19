### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(const void* a, const void* b)
{
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}

inline int Max(int a, int b)
{
    return a > b ? a : b;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if (!intervals || intervalsSize <= 0) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int*), Compare);
    int* dp = (int*)malloc(sizeof(int) * intervalsSize);
    dp[0] = 1;
    int max = 0;
    for (int i = 0; i < intervalsSize; i++) {
        max = 0;
        for (int j = 0; j < i; j++) {
            if (intervals[j][1] <= intervals[i][0]) {
                max = Max(max, dp[j]);
            }
        }
        dp[i] = max + 1;
    }
    int ret = intervalsSize - dp[intervalsSize - 1];
    free(dp);
    return ret;
}
```