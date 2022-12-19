### 解题思路

转化为01背包问题

考察是否能够选择一些物品，使其和为`sum / 2`


### 代码

```python3
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s & 1:
            return False
        dp = [False] * (s // 2 + 1)
        dp[0] = True
        for x in nums:
            for i in range(s // 2, x - 1, -1):
                    dp[i] = dp[i] or dp[i - x]
        return dp[-1]
        
```