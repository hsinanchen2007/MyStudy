### 解题思路
48 ms，9.3 MB
1.把所有区间按从左到右排序（左点从小到大排序，如果一样则按右点从小到大排序）
2.定义变量left,mid,righ，当前处理的区间中的第一个数在[left,mid]范围内，第二数在(mid,right]范围内，mid如果为-1表示[left,right]中随便选两个数
3.遍历排序后的所有区间，会存在如下几种场景:
    a.两个区间不相交，必然要在新区间再选2个数，更新left=leftPoint，right=rightPoint，mid = -1
    b.两个区间相交一个数，需要在新区间再选1个数，更新left = leftPoint，right = rightPoint，mid = leftPoint
    c.当mid有值且leftPoint > mid时，分两种场景更新left,right,mid，但还需要再选1个数:
        i.rightPoint > right
        ii.rightPoint <= right
    d.其他场景都不需要再新区间再选数了，更新left,right,mid即可

### 代码

```c

int Compare(const void *p1, const void *p2)
{
    int **interval1 = (int **)p1;
    int **interval2 = (int **)p2;

    if (interval1[0][0] == interval2[0][0]) {
        return interval1[0][1] - interval2[0][1];
    }

    return interval1[0][0] - interval2[0][0];
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize){
    int i;
    int count = 2;
    int left = 0;
    int right = 0;
    int mid = -1;
    int leftPoint = 0;
    int rightPoint = 0;

    if (intervalsSize <= 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int **), Compare);

    left = intervals[0][0];
    right = intervals[0][1];
    for (i = 1; i < intervalsSize; i++) {
        leftPoint = intervals[i][0];
        rightPoint = intervals[i][1];

        if (leftPoint > right) {
            count += 2;
            left = leftPoint;
            right = rightPoint;
            mid = -1;
        } else if (leftPoint == right) {
            count += 1;
            left = leftPoint;
            right = rightPoint;
            mid = leftPoint;
        } else if (mid != -1 && leftPoint > mid) {
            count += 1;
            if (rightPoint > right) {
                mid = right;
                right = right < rightPoint ? rightPoint : right;
            } else {
                mid = -1;
                right = right > rightPoint ? rightPoint : right;
            }
            left = leftPoint;
        } else {
            left = leftPoint;
            right = right > rightPoint ? rightPoint : right;
        }
    }

    return count;
}

```