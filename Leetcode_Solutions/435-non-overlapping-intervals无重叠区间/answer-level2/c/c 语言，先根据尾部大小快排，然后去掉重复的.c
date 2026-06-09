### 解题思路
此处撰写解题思路

### 代码

```c
int compare(const void *a, const void *b) {
    int *range1 = *(int **)a;
    int *range2 = *(int **)b;
    if (range1[1] == range2[1]) {
        return range2[0] - range1[0];
    }  else {
        return range1[1] - range2[1];
    } 
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervalsSize < 2) {
        return 0;
    }
    int num = 0;
    int temp = 0;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), compare);
    temp = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < temp) {
            ++num;
        } else {
            temp = intervals[i][1];
        }
    }
    return num;
}
```