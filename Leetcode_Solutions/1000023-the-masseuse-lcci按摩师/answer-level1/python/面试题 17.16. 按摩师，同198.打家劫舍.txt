### 解题思路
dp[k] = max(dp[k - 1], dp[k - 2] + nums[k])
当前下标为k时，有两种情况，一种选择nums[k]的,则就不能选择nums[k-1]的，所以此时的总的分钟就是dp[k-2]+nums[k],或者可能这种情况分钟数不大，不选择这种情况，继续延续上一dp[k-1]的选择。

### 代码

```python3
# 同198.打家劫舍
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        dp = [0] * (len(nums) + 1)
        dp[0] = nums[0]
        # dp[1] = nums[0]
        for k in range(1, len(nums)):
            dp[k] = max(dp[k - 1], dp[k - 2] + nums[k])
        return dp[len(nums) - 1]
```