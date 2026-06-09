```
//按照会议的开始时间进行排序。
int compare(const void * a, const void * b) {
    int * tempa = *(int **) a;
    int * tempb = *(int **) b;
    return tempa[0] - tempb[0];
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervals == NULL || intervalsSize == 0) {
        return true;
    }
    qsort(intervals, intervalsSize, sizeof(int *), compare);
    for(int i = 0; i < intervalsSize - 1; i++) {
        if(intervals[i][1] > intervals[i + 1][0]) {
            return false;
        }
    }
    return true;
}
```
