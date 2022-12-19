### 解题思路
dp[i][j] 定义为s[0....i] 与 p[0....j]是否匹配

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        # 对空字符串单独讨论
        if m == 0:
            if n == 0:
                return True
            return False
        if n == 0:
            for c in p:
                if c != '*':
                    return False
            return True
        dp = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                # base case
                if i == 0:
                    for k in range(0, j):
                        if p[k] == '*':
                            is_stars = True
                        else:
                            is_stars = False
                            break
                    dp[i][j] = i == j and p[j] in (s[i], '?', '*') or \
                               i < j and p[j] in (s[i], '?') and is_stars or \
                               i < j and p[j] == '*' and dp[i][j - 1]
                    continue
                # base case
                if j == 0:
                    dp[i][j] = i > j and p[j] == '*'
                    continue
                # 状态转移，if p[j] == '*' 则有三种情况都是匹配的，
                #  还有一种是是p[j] == '?' or s[i] 则前面的字符串匹配就行
                dp[i][j] = p[j] == '*' and (dp[i][j-1] or dp[i-1][j] or dp[i-1][j-1]) or \
                           p[j] in (s[i], '?') and dp[i - 1][j - 1]

        return dp[n - 1][m - 1]

```