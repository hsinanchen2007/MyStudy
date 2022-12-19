```
int findPeakElement(int *nums, int numsSize)
{
    if (!nums || numsSize < 1) {
        return 0;
    }
    if (numsSize == 1) {
        return 0;
    }
    if (nums[0] > nums[1]) {
        return 0;
    }
    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        return numsSize - 1;
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }
    printf("can not find!");
    return -1;
}
```
