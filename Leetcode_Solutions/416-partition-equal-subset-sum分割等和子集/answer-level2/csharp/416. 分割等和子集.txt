### 解题思路
C# 动态规划 优化DP数组维度

### 代码

```csharp
public class Solution {
    public bool CanPartition(int[] nums) {
        int sum = nums.Sum();
        if ((sum & 1) == 1 || nums.Length < 2) return false;
        if (nums.Length == 2) return nums[0] == nums[1];

        int target = sum >> 1;
        var set = new HashSet<int>(new[] { 0, nums[0] });
        for (int index = 1; index < nums.Length; index++)
        {
            var source = set.ToArray();
            foreach (var value in source)
            {
                var current = value + nums[index];
                if (current == target)
                {
                    return true;
                }
                else if (current < target)
                {
                    set.Add(current);
                }
            }
        }
        return false;
    }
}
```