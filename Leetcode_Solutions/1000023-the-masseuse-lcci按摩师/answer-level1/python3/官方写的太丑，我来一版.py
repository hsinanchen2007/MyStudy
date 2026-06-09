### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        # 和198题一样
        n = len(nums)
        if n == 0:
            return 0
        # 定义dp
        dp = [0 for i in range(n+1)]
        # base case
        dp[1] = nums[0]
        for i in range(2, n+1):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])
        return dp[n]
```