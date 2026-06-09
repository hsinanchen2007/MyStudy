```
/* 数组中出现次数超过一半以上的数 */
int cmp(const void *num1, const void *num2)
{
    return (*(int *)num1 - *(int *)num2);
}

int majorityElement(int* nums, int numsSize)
{
    int count = 1;
    int index;
    int checkNum = (numsSize % 2 == 0) ? (numsSize / 2) : (numsSize / 2 + 1);

    if (numsSize == 1) {
        return nums[0];
    }
    // 先对数组进行排序
    qsort(nums, numsSize, sizeof(int), cmp);

    for (index = 1; index < numsSize; index++) {
        if (nums[index] == nums[index - 1]) {
            count ++;
            if (count >= checkNum) {
                return nums[index];
            }
        } else {
            count = 1;
        }
    }

    return 0;
}
```
