### 解题思路
典型的二分查找题目。题目给了约束条件（数据和边界），保证结果的存在。这里给出C语言的解法。

注意理解使用的二分代码模板，即：

mid = （ll + rr）/ 2;       //中值向下取整

移动：ll = mid + 1；rr = mid，意味着边界发生移动，不会锁死在边界上。

本题的判定条件为nums[mid] 和 nums[mid + 1]的关系

![image.png](https://pic.leetcode-cn.com/367efaf92f1b5a017b0bca26ddf74cf5470490cd50f0759536cbd03e55a7fd4f-image.png)


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

//【算法思路】二分查找。
// 本题关键点在于题目条件：1.num[i] != num[i + 1]；2.num[-1] == num[n] == INT_MIN
// 因此根据mid点位置的变化趋势，即可以选择二分移动方向
// 这里注意二分模板，mid = (ll + rr) / 2;ll = mid + 1;rr = mid。隐含着搜索位置的移动
int findPeakElement(int* nums, int numsSize){
    if(numsSize == 1) {
        return 0;
    }

    int ll = 0, rr = numsSize - 1;

    while(ll < rr) {
        int mid = (ll + rr) / 2;

        if(nums[mid] < nums[mid + 1]) {
            ll = mid + 1;
        } else {
            rr = mid;
        }
    }

    return ll;
}
```