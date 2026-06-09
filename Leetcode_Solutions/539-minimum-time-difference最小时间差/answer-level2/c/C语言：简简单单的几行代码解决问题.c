![QQ截图20190721091304.png](https://pic.leetcode-cn.com/56b0dc09684cfb1dc61281bf40bb982137693f7eaaff7d484c869e6f3a723f46-QQ%E6%88%AA%E5%9B%BE20190721091304.png)
- 转换成分钟，排序后比较
```
#define DAY_MINU (24*60)
int  compare(const void *a,const void *b) {
    return (*((int*) a) - *((int*) b));
}
int findMinDifference(char ** timePoints, int timePointsSize){
    int minu_array[timePointsSize], hour, minu;
    for (int i = 0; i < timePointsSize; ++i) {
        sscanf(timePoints[i], "%d:%d", &hour, &minu);
        minu_array[i] = hour*60 + minu;
    }
    qsort(minu_array, timePointsSize, sizeof(int), compare);
    
    int min_point = 0x7fffffff;
    for (int i = 0; i < timePointsSize-1; ++i) {
        int tmp = minu_array[i+1] - minu_array[i];
        if (tmp == 0) return 0;  //没有比0更小的间隔了
        if (tmp < min_point) min_point = tmp;
    }

    return (DAY_MINU-minu_array[timePointsSize-1] + minu_array[0]) < min_point ?
           (DAY_MINU-minu_array[timePointsSize-1] + minu_array[0]) :
           min_point;
}
```
