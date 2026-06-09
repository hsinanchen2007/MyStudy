```python
class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:

        # A.length <= 500
        # B.length <= 500
        # Time complexity: O(MN)
        # Space complexity: O(N)

        l_a, l_b = len(A), len(B)
        dp = [0] * (l_b + 1)
        for i in range(1, l_a + 1):
            pre = dp[0]
            for j in range(1, l_b + 1):
                tmp = dp[j]
                if A[i - 1] == B[j - 1]:
                    dp[j] = pre + 1
                else:
                    dp[j] = max(dp[j - 1], dp[j])
                pre = tmp
        return dp[-1]
```