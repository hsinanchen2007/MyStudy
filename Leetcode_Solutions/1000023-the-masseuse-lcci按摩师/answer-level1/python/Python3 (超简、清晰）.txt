# 代码
时间复杂度：O(n)
空间复杂度：O(n))
``` python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0]*2 for _ in range(n+1)]
        for i in range(1, n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp[i][1] = nums[i-1] + dp[i-1][0]
        return max(dp[n][0], dp[n][1])
```
时间复杂度：O(n)
空间复杂度：O(1)
```python []
class Solution:
    def rob(self, nums: List[int]) -> int:
        yes, no = 0, 0
        for num in nums:
            yes, no = num + no, max(yes, no)
        return max(yes, no)

```