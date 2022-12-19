### 解题思路
先对数组排序，按照若右区间相等，比较左区间，否则直接比较左区间的原则，由小到大排序；
再遍历排序数组，先记录第一个右区间end，不重叠区间个数cnt = 1，每一次若左区间小于end则跳下一个元素，否则更新end，cnt++；
最后返回区间数减去cnt即可。

### 代码

```c
int cmp(const void*a,const void*b){
    int *p1 = *(int**)a,*p2 = *(int**)b;
    if(p1[1]==p2[1]) return p1[0]-p2[0];
    else return p1[1]-p2[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize==0) return 0;

    qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);

    /*for(int i = 0;i <intervalsSize;i++){
        for(int j = 0;j<*intervalsColSize;j++){
            printf("%d ",intervals[i][j]);
        }
        printf("\n");
    }*/

    int end = intervals[0][1];
    int cnt = 1;
    for(int i = 1;i < intervalsSize;i++){
        if(intervals[i][0]<end){
            continue;
        }
        end = intervals[i][1];
        cnt++;
    }
    
    return intervalsSize - cnt;
}
```