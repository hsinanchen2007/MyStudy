int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a; // 降序
}

int maximumGap(int* nums, int numsSize)
{
    if (numsSize < 2 || nums == NULL) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] == nums[i+1]) {
            continue;
        }
        return nums[i] - nums[i+1];
    }
    return nums[0] - nums[1];
}