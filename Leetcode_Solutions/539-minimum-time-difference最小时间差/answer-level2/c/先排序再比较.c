### 解题思路
先把时间转成分钟数，再排序，然后遍历得到最小间隔。
一定要记得比较最后一个和最开始一个的间隔，因为是个环。

### 代码

```c

// 时间转成分钟
int Change(char *str) 
{
    char t1[3];
    t1[0] = str[0];
    t1[1] = str[1];
    t1[2] = 0;
    int min = atoi(t1) * 60;
    t1[0] = str[3];
    t1[1] = str[4];
    t1[2] = 0;
    min += atoi(t1);
    return min;
}

int cmp(const void*a, const void* b) 
{
    return *(int*)a - *(int*)b;
}

int findMinDifference(char ** timePoints, int timePointsSize){
    int *mins = (int *)malloc(sizeof(int*) * timePointsSize);
    if (mins == NULL) {
        return -1;
    }
    for (int i = 0; i < timePointsSize; i++) {
        mins[i] = Change(timePoints[i]);
    }
    qsort(mins, timePointsSize, sizeof(int), cmp);
    
    int minDiff = INT_MAX;
    for (int i = 0; i < timePointsSize - 1; i++) {
        if (minDiff > (mins[i+1] - mins[i])) {
            minDiff = mins[i+1] - mins[i];
        }
        if (minDiff == 0) {
            break;
        }
    }
    int last = 24*60 - mins[timePointsSize -1]  + mins[0];
    minDiff = minDiff > last ?  last : minDiff;
    free(mins);
    return minDiff;
}
```