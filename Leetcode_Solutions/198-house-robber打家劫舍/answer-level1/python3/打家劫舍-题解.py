### 解题思路
此题参考了[官方题解](https://leetcode-cn.com/problems/the-masseuse-lcci/solution/an-mo-shi-by-leetcode-solution/)，讲解的很细致明白，规律很明显，感谢！

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        lgth = len(nums)
        if lgth == 0:
            return 0
        if lgth <= 2:
            return max(nums)

        dp0 = 0         # dp[i-1][0], 表示不偷第i-1个房屋
        dp1 = nums[0]   # dp[i-1][1], 表示偷第i-1个房屋

        for i in range(1, lgth):
            dp0_cur = max(dp0, dp1)   # dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp1_cur = dp0 + nums[i]   # dp[i][1] = dp[i-1][0] + nums[i]

            dp0, dp1 = dp0_cur, dp1_cur
        
        return max(dp0, dp1)
```