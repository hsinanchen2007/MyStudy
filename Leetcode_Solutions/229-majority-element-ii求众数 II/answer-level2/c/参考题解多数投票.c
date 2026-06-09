```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*最多有两个符合条件的，先进行投票找到候选人，在进行第二轮计算是否符合众数*/
int* majorityElement(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if (numsSize == 0) {
        return nums;
    }
    int num1 = nums[0];
    int num2 = nums[0];
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == num1) {
            count1++;
            continue;
        }
        if (nums[i] == num2) {
            count2++;
            continue;
        }
        if (count1 == 0) {
            num1 = nums[i];
            count1++;
            continue;
        }
        if (count2 == 0) {
            num2 = nums[i];
            count2++;
            continue;
        }
        count1--;
        count2--;
    }
    count1 = 0;
    count2 = 0;   
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == num1) {
            count1++;
            continue;
        }
        if (nums[i] == num2) {
            count2++;
            continue;
        }
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);
    if (count1 > numsSize / 3) {
        ret[*returnSize] = num1;
        (*returnSize)++;
    }
    if (count2 > numsSize / 3) {
        ret[*returnSize] = num2;
        (*returnSize)++;
    }
    return ret;
}
```
