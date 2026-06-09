### 解题思路
单调队列:
遍历数组:
1、从right到left当这个数前边有大于这个数的时候，直接将数弹出，并与当前的队首做比较，求tmp_max
因为已经遇到了一个比前边更小的数，如果后边出现最更大的数，肯定是以当前新加的为准，前边大的已经无意义
2、如果right小于当前，则入队列
因此维护了一个单调递增的队列

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAX_NODE 4096 * 100

static int data[MAX_NODE];
static int left;
static int right;

/*
单调队列:
遍历数组:
1、从right到left当这个数前边有大于这个数的时候，直接将数弹出，并与当前的队首做比较，求tmp_max
因为已经遇到了一个比前边更小的数，如果后边出现最更大的数，肯定是以当前新加的为准，前边大的已经无意义
2、如果right小于当前，则入队列
因此维护了一个单调递增的队列
*/

int maxProfit(int *prices, int pricesSize)
{
        int loop;
        int tmp_max;
        int max = 0;
        left = 0;
        right = 0;
        if (!prices || pricesSize < 1)
                return 0;
        data[right] = 0;
        right++;
        for (loop = 1; loop < pricesSize; loop++) {
                while(left < right && prices[data[right - 1]] > prices[loop]) {
                        tmp_max = prices[data[right - 1]] - prices[data[left]];
                        //printf("%d - %d\n", data[right - 1], data[left]);
                        max = MAX(max, tmp_max);
                        right--;
                }
                data[right++] = loop;
        }
        max = MAX(max, prices[data[right - 1]] - prices[data[left]]);
        //printf("max %d\n", max);
        return max;
}
```