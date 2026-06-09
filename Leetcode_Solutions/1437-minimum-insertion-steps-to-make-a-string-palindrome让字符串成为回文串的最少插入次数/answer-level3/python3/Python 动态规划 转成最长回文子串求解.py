![image.png](https://pic.leetcode-cn.com/754e349162ab3e0bae89bd41b16c323e8fef81b6259742e7a5c570031b060dd4-image.png)


```
'''
转成其他问题求解
求最长回文子串的长度，字符串总长度减去最长回文子串长度就是答案

dp(i, j) 表示[i, j]位置范围内的最长回文子串的长度

s[i] == s[j]:
    dp(i, j) = 2 + dp[i+1, j-1]
s[i] != s[j]:
    dp(i, j) = max(dp(i+1, j), dp(i, j-1))
'''


class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)

        dp = [[1 for _ in range(n)] for _ in range(n)]
        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1] if j - i >= 2 else 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]) if j - i >= 2 else 1
        return n - dp[0][n-1]
```
