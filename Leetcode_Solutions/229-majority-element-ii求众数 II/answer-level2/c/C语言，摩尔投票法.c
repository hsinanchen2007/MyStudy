### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
    假定 num1，num2 为出现次数大于 nums.length / 3 的两个数。（最多出现两个）
    遍历 nums， 若出现 num1、num2 中任意一数，计数+1，若都不等，则计数-1.
    若 num1、num2 有一个计数 < 0，则替换成当前遍历数（更换新的众数）
    数组可能出现 无众数 或只有 一众数 情况，所以需要再次遍历数组，统计所选众数出现次数，将满足条件（出现次数大于 nums.length / 3 ）的数加入返回集合。
*/

int* majorityElement(int* nums, int numsSize, int* returnSize){
    int *arr = NULL;
    int can1, can2;
    int cnt1 = 0, cnt2 = 0;
    int i;

    if (nums == NULL || numsSize <= 1) {
        *returnSize = numsSize;
        return nums;
    } 
    can1 = nums[0];
    can2 = nums[1];
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == can1) {
            cnt1++;
            continue;
        } else if (nums[i] == can2) {
            cnt2++;
            continue;
        } else {
            cnt1--;
            cnt2--;
        }

        /* 保证每次只替换一个数据 */
        if (cnt1 < 0) {
            can1 = nums[i];
            cnt1 = 1;
            cnt2++;
        }

        if (cnt2 < 0) {
            can2 = nums[i];
            cnt2 = 1;
            cnt1++;
        }            
    }
    
    cnt1 = 0;
    cnt2 = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == can1)  {
            cnt1++;
        } else if (nums[i] == can2) {
            cnt2++;
        }
    }

    arr = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0;
    i = 0;
    if (cnt1 > numsSize / 3) {
        arr[i++] = can1;
        *returnSize += 1;
    }
    if (cnt2 > numsSize / 3) {
        arr[i++] = can2;
        *returnSize += 1;
    }

    return arr;
}

```