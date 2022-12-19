### 解题思路
使用动态规划来解决此题

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0]*2 for i in range(n+1)]
        for i in range(1, n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp[i][1] = nums[i-1] + dp[i-1][0]
        return max(dp[n][0], dp[n][1])

```