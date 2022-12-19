### 解题思路

如果我今天放假了，那工资最多是昨天休息或昨天工作两种可能中较多的；如果今天工作，说明昨天休息，工资最多是前天工作和前天休息中较多的 + 今天的工资。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp = {(-1, 0): 0, (-2, 0):0, (-1, 1): -float('inf'), (-2, 1): -float('inf')}
        for i, num in enumerate(nums):
            dp[(i, 0)] = max(dp[(i-1, 0)], dp[(i-1, 1)])
            dp[(i, 1)] = max(dp[i-2, 1], dp[(i-2, 0)]) + num
        if nums:
            return max(dp[(i, 0)], dp[(i, 1)])
        else:
            return 0

```