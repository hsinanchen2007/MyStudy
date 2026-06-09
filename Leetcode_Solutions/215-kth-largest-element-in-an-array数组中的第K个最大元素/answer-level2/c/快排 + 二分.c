```
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int median(int* nums, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (nums[left] > nums[mid]) {
        swap(&nums[left], &nums[mid]);
    }
    if (nums[left] > nums[right - 1]) {
        swap(&nums[left], &nums[right - 1]);
    }
    if (nums[mid] < nums[right - 1]) {
        swap(&nums[mid], &nums[right - 1]);
    }
    return nums[right - 1];
}

int findKthLargest(int* nums, int numsSize, int k)
{
    if (numsSize < 2) {
        return nums[0];
    }
    int privot = median(nums, 0, numsSize);
    int le = 0, ri = numsSize - 1;
    while (le < ri) {
        while(nums[++le] < privot){};
        while(nums[--ri] > privot){};
        if (le < ri) {
            swap(&nums[le], &nums[ri]);
        }
    }
    swap(&nums[le], &nums[numsSize - 1]);
    int aimK = numsSize - k;
    if (le < aimK) {
        return findKthLargest(nums + le + 1, numsSize - le - 1, k);
    } else if (le == aimK) {
        return nums[le];
    } else if (le > aimK) {
        return findKthLargest(nums, le, k - (numsSize - le));
    }
    return 0;
}
```
