```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # the maximum length is 1,000
        # bbb // ab
        # dp[i][j] = dp[i + 1][j - 1] + 2
        # Time complexity : O(N ** 2)
        # Space complexity: O(N)
        if s == '': return 0
        dp = [0] * len(s)
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                tmp = dp[j]
                if i == j:
                    dp[j] = 1
                elif s[i] == s[j]:
                    dp[j] =  pre + 2
                else:
                    dp[j] = max( dp[j - 1], dp[j])
                pre = tmp
        return dp[-1]
```