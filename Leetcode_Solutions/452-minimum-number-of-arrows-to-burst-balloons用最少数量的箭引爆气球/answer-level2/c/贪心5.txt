### 解题思路
关键是开始需要先对二维数组排序，用qsort排序。
接下来的贪心思维比较简单，定义一个射击区间，射击区间的begin取气球的start，end取气球的end，然后逐个比较气球，如果气球的start大于射击区间的start，且小于射击区间的end，则更新射击区间，直到下一个气球的start>射击区间的end，则更新一个新的射击区间。

### 代码

```c
int comp(const void *a,const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;

    if(ap[0] == bp[0])
        return ap[1] - bp[1];
    else
        return ap[0] - bp[0];
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    
    if (pointsSize == 0)
    {
        return 0;
    }
    
    qsort(points, pointsSize, sizeof(points[0]), comp);

    //记录射击区间，初始化为第一个气球的start和end
    int shootBegin = points[0][0];
    int shootEnd = points[0][1];
    int shootTimes = 1;

    for (int i = 1; i < pointsSize; i ++)
    {
        if (points[i][0] >= shootBegin && shootEnd >= points[i][0])
        {
            shootBegin = points[i][0];
            if (points[i][1] <= shootEnd)
            {
                shootEnd = points[i][1];
            }
        }
        else
        {
            shootTimes ++;
            shootBegin = points[i][0];
            shootEnd = points[i][1];
        }
    }

    return shootTimes;
}
```