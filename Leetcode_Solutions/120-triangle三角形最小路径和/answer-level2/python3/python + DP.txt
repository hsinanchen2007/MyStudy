```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # pre = float('inf)
        # temp = dp[j]
        # dp[j] = min(pre, dp[j]) + triangle[i][j]
        # pre = temp
        
        # Time complexity: O(N2)
        # Space complexity: O(N)
        if triangle == []: return 0
        length = len(triangle)
        dp = [float('inf')] * length
        dp[0] = 0
        for i in range(length):
            pre = float('inf')
            for j in range(i + 1):
                temp = dp[j]
                dp[j] = min(pre, dp[j]) + triangle[i][j]
                pre = temp
        return min(dp)
```