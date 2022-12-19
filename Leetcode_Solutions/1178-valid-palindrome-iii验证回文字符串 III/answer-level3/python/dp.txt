原字符串 s 和反转字符串 t：dp[i][j] 表示 s 的前 i 位和 t 的前 j 位中，相同数字的个数。


```python
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        t = s[::-1]
        L = len(s)
        dp = [[0]*(L+1) for _ in range(L+1)]
        
        for i in range(1, L+1):
            for j in range(1, L+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        
        return dp[L][L] + k >= L
```