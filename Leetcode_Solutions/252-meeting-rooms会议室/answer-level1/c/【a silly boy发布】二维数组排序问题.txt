```
int cmp(const void *a, const void *b) {
    int *tmpA = *(int **)a;
    int *tmpB = *(int **)b;

    return *(int *)tmpA - *(int *)tmpB;
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize){
    int i;
    if ((intervals == NULL) || (intervalsSize == 0)) {
        return true;
    }
    if (intervalsSize == 1) {
        return true;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

    for (i = 0; i < intervalsSize - 1; i++) {
        if (intervals[i][1] > intervals[i + 1][0]) {
            return false;
        }
    }

    return true;
}
```
