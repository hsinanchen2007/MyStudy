### 解题思路
最长回文子串


### 代码

```python3
class Solution:
    def minInsertions(self, s: str) -> int:
        if not s:
            return 0
        dp = [[0 for _ in s] for _ in s]
        n = len(dp)
        for i in range(n):
            dp[i][i] = 1
        for i in range(n)[::-1]:  
            for j in range(i + 1, n):  
                if s[i] == s[j]:
                    if j == i + 1:
                        dp[i][j] = 2
                    else:
                        dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return n - dp[0][-1]
```