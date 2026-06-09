### 解题思路
典型的贪心算法，跳跃类型问题。

主要算法思路为，先确定一步范围，然后将范围内的数据用于确定下一次范围。

此类问题解法如下：

1.关键三个变量：起点，当前范围和下次范围

2.在当前范围内，更新下次范围

3.统计信息，更新起点，当前和下次范围

4.统计时，区分连续扩展区间，和新开辟区间

5.结束时，注意统计最后一次信息

![image.png](https://pic.leetcode-cn.com/9a69cfbf12245c2a762b4bdd79e3da564ce62977d43d33d6e0f2626982c0cbbb-image.png)


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

//【算法思路】贪心。典型的跳跃问题。
// 1.需要记录起点，当前界限和下一次界限。
// 2.需要区分连续扩展区间和新开辟区间。
// 3.本题难点为计时边界的处理。
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    if(timeSeriesSize == 0) {
        return 0;
    }

    int cid = 0;
    int pre = timeSeries[cid];
    int cur = timeSeries[cid] + duration - 1;
    int nxt = -1;
    cid++;

    //计时起点加1
    int ret = 1;

    //printf("pre = %d, cur = %d, nxt = %d, ret = %d\n", pre, cur, nxt, ret);

    while(cid < timeSeriesSize) {
        if(timeSeries[cid] < cur) {
            nxt = timeSeries[cid] + duration - 1;
            cid++;
            continue;
        }

        //结算当前，只记录增量
        ret += cur - pre;

        //更新下一次查找，区分连续扩展和新开辟
        if(nxt == -1) {
            //新开盘区间
            pre = timeSeries[cid] == cur? timeSeries[cid] + 1 : timeSeries[cid];
            cur = timeSeries[cid] + duration - 1;
            nxt = -1;

            //计时起点加1
            ret += 1;

            cid++;
        } else {
            //原区间递增
            pre = cur;
            cur = nxt;
            nxt = -1;
        }

        //printf("pre = %d, cur = %d, nxt = %d, ret = %d\n", pre, cur, nxt, ret);
    }

    //最后一次处理，只记录增量
    ret += cur - pre;

    if(nxt != -1) {
        //统计扩展区间，只记录增量
        ret += nxt - cur;
    }

    //printf("pre = %d, cur = %d, nxt = %d, ret = %d\n", pre, cur, nxt, ret);

    return ret;
}
```