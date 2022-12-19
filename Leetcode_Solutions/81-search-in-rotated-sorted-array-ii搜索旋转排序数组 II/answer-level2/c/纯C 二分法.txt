### 解题思路
二分法

### 代码

```c
bool search(int* nums, int numsSize, int target){
    if (0 == numsSize)
    {
        return false;
    }

    int low = 0;
    int high = numsSize - 1;
    int mid = 0;

    while (low + 1 < high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[low] < nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        else if (nums[mid] < nums[low])
        {
            if (nums[mid] <= target && target <=nums[high])
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        else if (nums[low] == nums[mid])
        {
            low++;
        }
    }

    if (nums[low] == target || nums[high] == target)
    {
        return true;
    }

    return false;
}
```