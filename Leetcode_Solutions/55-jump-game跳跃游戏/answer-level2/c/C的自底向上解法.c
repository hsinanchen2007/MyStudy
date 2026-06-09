### 解题思路
此处撰写解题思路
C的自底向上解法，类似钢条分割，即先保证最后一个位置肯定是满足条件的，然后最小规模应该是倒数第二个点是否能到达最后一个点，然后保存该点是不是OK的信息，再看往左看，此时右边的点都是可达的
### 代码

```c
#include <stdio.h>
#include <stdlib.h>

char *g_mem_array = NULL;

bool cal_canJump(int* nums, int numsSize, int pos)
{
    int i, j;
    int tmp = 0;

    g_mem_array[numsSize - 1] = 1;
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] + i > numsSize - 1) {
            tmp = numsSize - 1;
        } else {
            tmp = nums[i] + i;
        }
        //printf("i:%d tmp:%d\n", i, tmp);
        for (j = i + 1; j <= tmp; j++) {
            //printf("g_mem_array[%d]:%d\n", j, g_mem_array[j]);
            if (g_mem_array[j] == 1) {
                g_mem_array[i] = 1;
                break;
            }
        }
    }

    return g_mem_array[0] == 1;
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