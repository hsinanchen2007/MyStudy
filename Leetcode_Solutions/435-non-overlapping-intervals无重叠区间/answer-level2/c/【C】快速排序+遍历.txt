1. 将各区间按照起始点从小到大排序；
2. 从头遍历各区间：
   (1) 如果当前区间和上一个区间有重叠，count++;
   (2) 如果当前区间和上一个区间无重叠，pre = current;
3. 返回count;


```
int SelfCompare(const void *p, const void *q)
{
    int **m = (int **)p;
    int **n = (int **)q;
    if ((*m)[0] == (*n)[0]) {
        return (*m)[1] - (*n)[1];
    } else {
        return (*m)[0] - (*n)[0];   
    }
}

#define NO_OVERLAP 0
#define OVERLAP_SAME_START 1
#define OVERLAP_LOCATE_IN 2
#define OVERLAP_LOCATE_OVER 3

static int IsOverlap(int **intervals, int i, int pre)
{
    int ret = NO_OVERLAP;
    if (intervals[pre][0] == intervals[i][0]) {
        ret = OVERLAP_SAME_START;
    } else if (intervals[pre][1] > intervals[i][0] && intervals[pre][1] <= intervals[i][1]) {
        ret = OVERLAP_LOCATE_IN;
    } else if (intervals[pre][1] > intervals[i][1]) {
        ret = OVERLAP_LOCATE_OVER;
    }
    return ret;
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){

    if (intervals == NULL || intervalsSize < 2 || intervalsColSize == NULL) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int *), SelfCompare);
    int ret = 0;
    int pre = 0;
    int i = pre + 1;
    while (i < intervalsSize) {
        int flag = IsOverlap(intervals, i, pre);
        if (flag != NO_OVERLAP) {
            ret++;
        } else {
            pre = i;
        }
        if (flag == OVERLAP_LOCATE_OVER) {
            intervals[pre][0] = intervals[i][0];
            intervals[pre][1] = intervals[i][1];
        }
        i++;
    }
    return ret;
}
```

