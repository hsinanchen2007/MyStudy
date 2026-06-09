```
int findMin(int* nums, int numsSize)
{
    int left, right, mid;
    left = 0;
    right = numsSize - 1;
    if (nums[0] < nums[numsSize - 1]) { 
        return nums[0];
    }
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] >= nums[0]) {
            left = left + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}
```
