```python
class Solution:
    def maxA(self, N: int) -> int:
        # Time complexity : O(N ** 2)
        # Space complexity : O(N)
        dp = [i for i in range(N + 1)]
        for i in range(4, N + 1):
            for j in range(1, i - 2):
                dp[i] = max(dp[i], (i - j - 1) * dp[j])
        return dp[-1]
```