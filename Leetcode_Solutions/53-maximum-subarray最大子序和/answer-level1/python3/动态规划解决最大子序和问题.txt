### 解题思路
使用动态规划的解法，设置dp数组保存当前位置的最大子序和，可知当前位置的子序和要么是当前位置的值，要么是
当前位置的值加上前一个位置的最大子序和，即dp[i] = max(dp[i-1]+nums[i], nums[i])。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0 for _ in range(len(nums))]
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
        return max(dp)
```