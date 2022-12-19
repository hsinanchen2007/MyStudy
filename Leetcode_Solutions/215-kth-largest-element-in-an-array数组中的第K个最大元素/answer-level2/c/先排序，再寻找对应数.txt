int inc(const void *a, const void *b)
{
    return ((*(int *)a) - (*(int *)b));
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(nums[0]), inc);
    return nums[numsSize - k];
}