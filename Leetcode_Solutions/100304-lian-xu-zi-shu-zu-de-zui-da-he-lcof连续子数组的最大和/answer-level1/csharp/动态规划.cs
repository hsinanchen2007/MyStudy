### 解题思路
动态规划，计算出所有以i(i >= 0 && i <=nums.Length)结尾的最大子数组和，然后在这些和中取最大的。

### 代码

```csharp
public class Solution {
    public int MaxSubArray(int[] nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for(int i = 1; i < nums.Length; i++)
        {
            currentSum = Math.Max(currentSum + nums[i], nums[i]);
            maxSum = Math.Max(currentSum, maxSum);
        }

        return maxSum;
    }
}
```