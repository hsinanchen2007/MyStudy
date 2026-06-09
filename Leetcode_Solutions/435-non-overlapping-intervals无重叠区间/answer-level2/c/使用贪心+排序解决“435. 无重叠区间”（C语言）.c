### 解题思路
贪心算法，思路为两个重叠区间，要保留尾部更小的区间。这里给出C语言的解法。

1.对区间按照左边界排序

2.从第一个区间开始，判断区间尾部和后面区间的关系。

3.如果尾部小于后面区间头部，则向后处理

4.如果尾部大于后面区间头部，则进行区间删除，即判断当前区间和后面区间的尾部位置，保留位置靠前的区间

![image.png](https://pic.leetcode-cn.com/9d3f58f0167bfa5ce206bf83f40d628207d25c226141429008fb448268aa020b-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int compare(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

//【算法思路】贪心算法。区间问题，排序后，重叠区域里面右边界最短的区间保留。
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize <= 1) {
        return 0;
    }

    //按照区间左边排序，然后查找右边尾部的覆盖情况
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int ret = 0;

    //记录当前保留的区间id
    int cid = 0;
    //记录当前保留区间的尾部
    int tail = intervals[cid][1];
    //记录下一个判断的区间
    int nid = cid + 1;

    while(nid < intervalsSize) {
        if(intervals[nid][0] < tail) {
            //如果nid和cid区间相交，选择尾部更短的更新参数
            if(intervals[nid][1] < tail) {
                tail = intervals[nid][1];
                cid = nid;
            }

            nid++;
            ret++;
        } else {
            cid = nid;
            tail = intervals[cid][1];
            nid = cid + 1;
        }
    }

    return ret;
}
```