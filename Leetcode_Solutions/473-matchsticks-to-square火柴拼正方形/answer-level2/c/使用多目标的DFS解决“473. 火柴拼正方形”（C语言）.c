### 解题思路
经典的多目标DFS题目。特点为**递归函数需要达成多个目标，或多次目标**。这里给出C语言的解法。

1.首先求得边长，并对结果做初步判断。

2.调用递归函数，递归函数根据当前处理的id，当前目标，和到达目标的次数，进行判断。

3.在递归函数中，遍历剩余元素

4.如果该元素没有被使用，进行步骤5

5.如果当前元素等于目标，并且已经达到4次，返回true；否则更新id为0，目标为边长，次数加一进行下一步递归

6.如果当前元素不等于目标，使用该元素，更新目标和id，进行递归。

![image.png](https://pic.leetcode-cn.com/b8b9fc5671afc7337c4adefe3809f88a0e84c24e30f3361f5d71c4d170c9fe3c-image.png)


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
    return *(int *)a - *(int *)b;
}

int g_target;

//如果没有到达target，则递增；如果到达target，则增加cnt。如果cnt == 4，返回true
bool helper(int* nums, int numsSize, int *flags, int id, int target, int cnt) {
/*
    printf("id = %d, target = %d, cnt = %d\n", id, target, cnt);
    for(int i = 0; i < numsSize; i++) {
        printf("<%d>%d   ", i, flags[i]);
    }
    printf("\n\n");
*/
    bool ret = false;

    for(int i = id; i < numsSize; i++) {
        if(target < nums[i]) {
            //数据单调增，加速
            break;
        } else if(flags[i] == 1) {
            //数据已经使用过
            continue;
        }

        if(nums[i] == target) {
            if(cnt + 1 == 4) {
                return true;
            } else {
                flags[i] = 1;
                ret = helper(nums, numsSize, flags, 0, g_target, cnt + 1);
                if(ret == true) {
                    break;
                }
                flags[i] = 0;
            }
        } else {
            int new_tar = target - nums[i];

            flags[i] = 1;
            ret = helper(nums, numsSize, flags, i + 1, new_tar, cnt);
            if(ret == true) {
                break;
            }
            flags[i] = 0;
        }
    }

    return ret;
}

//【算法思路】DFS。经典的多目标dfs，当遍历一次完成后，重新开始遍历直至结束
bool makesquare(int* nums, int numsSize){
    if(numsSize < 4) {
        return false;
    }

    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    if(sum % 4 != 0) {
        return false;
    }

    g_target = sum / 4;

    qsort(nums, numsSize, sizeof(int), compare);

    int *flags = (int *)calloc(numsSize, sizeof(int));

    bool ret = helper(nums, numsSize, flags, 0, g_target, 0);

    return ret;
}
```