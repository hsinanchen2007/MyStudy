### 解题思路
此处撰写解题思路
开始学动态规划的第一题 用的等价的自定向下记忆法 其他更牛逼的解法在探索中
### 代码

```c
#include <stdio.h>
#include <stdlib.h>

char *g_mem_array = NULL;

bool cal_canJump(int* nums, int numsSize, int pos)
{
    bool ret;
    int tmp = nums[0];

    if (tmp >= numsSize - 1) {
        //printf("tmp:%d numsSize:%d\n", tmp, numsSize);
        return 1;
    }
    if (g_mem_array[pos] == 0 || g_mem_array[pos] == 1) {
        //printf("g_mem_array[%d]:%d\n", pos, g_mem_array[pos]);
        return g_mem_array[pos];
    }
    
    while (tmp != 0) { /* nums[0] is 0 means we cant go any further */
        ret = cal_canJump(&nums[tmp], numsSize - tmp, pos + tmp);
        if (ret == 1) {
            g_mem_array[pos] = 1;
            //printf("g_mem_array[%d] is 1\n", pos);
            return 1;
        } 
        tmp--;
    }
    g_mem_array[pos] = 0;
    //printf("g_mem_array[%d] is 0\n", pos);

    return 0;
}

bool canJump(int* nums, int numsSize)
{
    bool ret;
    int i;

    g_mem_array = (char *)malloc(numsSize);
    for (i = 0; i < numsSize; i++) {
        g_mem_array[i] = 0xff;
    }
    
    return cal_canJump(nums, numsSize, 0);
}

```