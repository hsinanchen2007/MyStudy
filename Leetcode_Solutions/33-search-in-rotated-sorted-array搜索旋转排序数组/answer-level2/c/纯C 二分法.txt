### 解题思路
纯C 二分法

### 代码

```c
int search(int* nums, int numsSize, int target){
    if (0 == numsSize)
    {
        return -1;
    }

    int low = 0;
    int high = numsSize - 1;
    int mid = 0;

    while (low + 1 < high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[low] < nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid;
            }
            else if (nums[mid] < target || target <= nums[low])
            {
                low = mid;
            }
        }
        else if (nums[mid] < nums[low])
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid;
            }
            else if (nums[high] <= target || target < nums[mid])
            {
                high = mid;
            }
        }
    }

    if (target == nums[low])
    {
        return low;
    }

    if (target == nums[high])
    {
        return high;
    }

    return -1;
}
```