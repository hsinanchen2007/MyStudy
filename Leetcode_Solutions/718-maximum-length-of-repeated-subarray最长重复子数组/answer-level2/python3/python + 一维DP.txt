```python
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        # use dp
        # dp[i][j] = dp[i - 1][j - 1] + 1
        len_a, len_b = len(A), len(B)
        dp = [0] * len_b
        ans = 0
        for i in range(len_a):
            pre = 0
            for j in range(len_b):
                temp = dp[j]
                if A[i] == B[j]:
                    if i > 0 and j > 0: dp[j] = pre + 1
                    else: dp[j] = 1
                else: dp[j] = 0
                pre = temp
            ans = max(ans, max(dp))
        return ans
```