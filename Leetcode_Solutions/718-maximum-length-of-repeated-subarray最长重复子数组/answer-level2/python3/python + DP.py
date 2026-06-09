```python
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        # use dp
        # dp[i][j] = dp[i - 1][j - 1] + 1
        len_a, len_b = len(A), len(B)
        dp = [[0] * len_b for _ in range(len_a)]
        for i in range(len_a):
            for j in range(len_b):
                if A[i] == B[j]:
                    if i > 0 and j > 0:
                        dp[i][j] = dp[i -1][j - 1] + 1
                    else: dp[i][j]  =1
        return max(map(max, dp))
```