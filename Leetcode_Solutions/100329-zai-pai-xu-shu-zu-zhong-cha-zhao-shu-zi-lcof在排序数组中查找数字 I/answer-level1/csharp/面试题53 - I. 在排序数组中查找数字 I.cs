### 解题思路
C# 分别查询两个边界

### 代码

```csharp
public class Solution {
    public int Search(int[] nums, int target) {
        int start = 0, end = nums.Length - 1;
        int middle = 0;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] <= target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        int right = start;

        start = 0;
        end = nums.Length - 1;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] >= target)
            {
                end = middle - 1;
            }
            else
            {
                start = middle + 1;
            }
        }
        int left = end;
        return right - left - 1;
    }
}
```