### 解题思路
动态规划

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        # dp[i]代表以元素nums[i]为结尾的连续子数组最大和
        dp = [float('-inf') for _ in range(n)]
        dp[0] = nums[0]
        for i in range(1, n):
            if dp[i - 1] < 0:
                dp[i] = nums[i]
            else:
                dp[i] = dp[i - 1] + nums[i]
        return max(dp)
```