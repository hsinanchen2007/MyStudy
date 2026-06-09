### 解题思路
暴力法，时间复杂度O(2^n),超出时间限制
动态规划法，定义dp[i][j]表示nums中前i个元素组成j的次数
核心状态转移方程式：dp[i][j + nums[i]] += dp[i - 1][j]，dp[i][j - nums[i]] += dp[i - 1][j]
### 代码

```python3
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        res = 0
        if nums and S <= 1000:
            dp = [[0 for i in range(2001)] for j in range(len(nums))]

            dp[0][1000 + nums[0]] += 1
            dp[0][1000 - nums[0]] += 1

            for i in range(1, len(nums)):
                for j in range(2001):
                    if dp[i - 1][j] > 0:
                        dp[i][j + nums[i]] += dp[i - 1][j]
                        dp[i][j - nums[i]] += dp[i - 1][j]

            res = dp[len(nums) - 1][S + 1000]

        return res
```