### 解题思路
二分法求左右索引

### 代码

```csharp
public class Solution {
    public int Search(int[] nums, int target) {
        if(nums == null || nums.Length == 0)
        {
            return 0;
        }
        if(GetLastEqualIndex(nums,target) == -1)
        {
            return 0;
        }
        return GetLastEqualIndex(nums,target) - GetFirstEqualIndex(nums, target) + 1;
    }

    private int GetFirstEqualIndex(int[] nums, int target)
    {
        int left = 0;
        int right = nums.Length -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                if(mid - 1 < 0 || nums[mid - 1] < target)
                {
                    return mid;
                }
                right = mid - 1;
            }else if(nums[mid] > target)
            {
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return -1;
    }

    private int GetLastEqualIndex(int[] nums, int target)
    {
        int left = 0;
        int right = nums.Length -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                if(mid + 1 > right || nums[mid + 1] > target)
                {
                    return mid;
                }
                left = mid + 1;
            }else if(nums[mid] > target)
            {
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return -1;
    }
}
```