### 解题思路
典型的贪心问题，如果出现和之前相同的方向，直接使用新值更新即可，这样更容易获得新的折线。

这里给出C语言的解法。

1.申请空间存储数据

2.记录之前上升或下降的趋势

3.如果趋势相反，则记录新值，更新趋势

4.如果趋势相同，则用新值替换，这样更容易获得新的折线（贪心）

5.如果相同则忽略

![image.png](https://pic.leetcode-cn.com/bb80798657496d9e552b35646480706f159b8d2806b975586ddd4d8a6d7b7e89-image.png)


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

//【算法思路】贪心算法。每一次折线，方向相同时，刷新新值，这样更容易获得新的折线。
int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2) {
        return numsSize;
    } else if(numsSize == 2) {
        return nums[1] == nums[0]? 1 : 2;
    }

    int *ret = (int *)calloc(numsSize, sizeof(int));
    int rsize = 0;

    ret[rsize++] = nums[0];
    int is_up = -1;

    for(int i = 1; i < numsSize; i++) {
        //如果和顶部元素相同，则继续
        if(nums[i] == ret[rsize - 1]) {
            continue;
        }

        if(is_up == -1) {
            //初次处理，对is_up标志赋值
            is_up = nums[i] > ret[rsize - 1]? 1 : 0;
            ret[rsize++] = nums[i];
        } else if(is_up == 0) {
            //之前为下降
            if(nums[i] > ret[rsize - 1]) {
                is_up = 1;
                ret[rsize++] = nums[i];
            } else {
                ret[rsize - 1] = nums[i];
            }
        } else if(is_up == 1) {
            //之前为上升
            if(nums[i] > ret[rsize - 1]) {
                ret[rsize - 1] = nums[i];
            } else {
                is_up = 0;
                ret[rsize++] = nums[i];
            }
        }
    }

    return rsize;
}
```