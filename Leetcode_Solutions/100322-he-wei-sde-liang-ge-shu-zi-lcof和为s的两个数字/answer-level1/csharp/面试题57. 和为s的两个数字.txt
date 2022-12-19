### 解题思路
C# 双指针 时间：O(n) 空间：O(1)

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int start = 0, end = nums.Length - 1;
        while (start < end)
        {
            if (nums[start] + nums[end] > target)
            {
                end--;
            }
            else if (nums[start] + nums[end] < target)
            {
                start++;
            }
            else
            {
                return new[] { nums[start], nums[end] };
            }
        }

        return Array.Empty<int>();
    }
}
```