### 解题思路
首先，将时间点按从00:00到23:59排序，利用C语言自带强大的qsort函数。

然后，依次计算两个时间点之间的间隔，由于已经排过序，直接用后者减去前者即可得到；保留间隔最小的。

最后，还要看一下最后的时间点与最开始的时间点之间的间隔，因为时间是循环的。
利用24:00到最后一个时间点的间隔 加上 第一个时间点到00:00的间隔即可。

### 代码

```c
#define MIN(a,b) ((a<b) ? a : b)

int cmp(const void *a, const void *b){
    char *ap = *(char **)a;       
    char *bp = *(char **)b;

    if(ap[0] != bp[0])
        return ap[0] - bp[0];
    
    if(ap[1] != bp[1])
        return ap[1] - bp[1];
    
    if(ap[3] != bp[3])
        return ap[3] - bp[3];
    
    return ap[4] - bp[4];
}

int getdiff(char * p1, char * p2){
    int i, j, k, l;
    i = p2[0] - p1[0];
    j = p2[1] - p1[1];
    k = p2[3] - p1[3];
    l = p2[4] - p1[4];
    return (i*10+j)*60 + (k*10+l);
}

int findMinDifference(char ** timePoints, int timePointsSize){
    int count=1440, i;
    char dlimit[6] = "00:00";
    char tlimit[6] = "24:00";

    qsort(timePoints, timePointsSize, sizeof(char *), cmp);

    for(i=1; i<timePointsSize; i++)
        count = MIN(count, getdiff(timePoints[i-1], timePoints[i]));
    
    return MIN(count, getdiff(timePoints[timePointsSize-1], tlimit) + getdiff(dlimit, timePoints[0]));
}
```