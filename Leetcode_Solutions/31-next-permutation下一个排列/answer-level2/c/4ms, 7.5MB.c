### 解题思路
后序找到第一个位置P，使得对P后面存在比P对应值稍大的位置Q；
P和Q对应值进行交换；
对P后的所有元素进行升序排列。

### 代码

```c
#include <stdio.h>
#include <string.h>

int cmp(void *a, void *b) 
{
    return (*(int*)a - *(int*)b);
}

void nextPermutation(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 1) {
        return;
    }
    int l = numsSize - 2;
    int r = numsSize - 1;
    while (l >= 0) {
        // 从l的后面找一个比l第一个大的数
        r = numsSize - 1;
        int min = 0;
        while (r > l) {
            if (nums[l] < nums[r]) {
                if (min == 0 || nums[r] < nums[min]) {
                    min = r;
                }
            }  
            r--;
        }
        //printf("min: %u", min);
        if (min != 0) {
            // 进行交换
            int tmp = nums[min];
            nums[min] = nums[l];
            nums[l] = tmp;
            // 再将l后面的所有数字进行升序排序
            //sort(&nums[l + 1], numsSize - 1 - l);
            qsort(&nums[l + 1], numsSize - 1 - l, sizeof(int), cmp);
            return;
        }

        l--;
    }
    l = 0;
    r = numsSize - 1;
    while (l < r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
    return;
}
```