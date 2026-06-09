```
int cmp(const void *a, const void *b) {
    const int *l = *(int **)a;
    const int *r = *(int **)b;
    return l[1] > r[1] ? 1 : -1;
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervalsSize <= 1) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int)*2, cmp);
    int count = 0;
    int max = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (max > intervals[i][0]) {
            count++;
        }else {
            max = intervals[i][1];
        }
    }
    return count;
}
```
