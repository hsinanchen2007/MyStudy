### 解题思路
之前有个大神写了一篇详解动态规划，十分受用。这里就是直接把动态规划拿过来用了，很简单地解决了问题

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        dp = [[0] * 2 for i in range(len(nums) + 1)]
        for i in range(0, len(nums)):
            dp[i][0] = 0
            dp[i][1] = -float('inf')
        dp[0][0], dp[0][1] = 0, nums[0]
        for i in range(1, len(nums)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
            dp[i][1] = max(dp[i - 1][1] - nums[i - 1] + nums[i], dp[i - 1][0] + nums[i])
            #print(dp[i])
        return max(dp[i][0], dp[i][1])
        
```