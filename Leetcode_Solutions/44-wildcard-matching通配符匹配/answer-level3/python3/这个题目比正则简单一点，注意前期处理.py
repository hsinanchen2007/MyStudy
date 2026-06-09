### 解题思路
前处理，当j==*时，结果等于*前面那个
```
for j in range(1, len_p + 1):
    if p[j - 1] == "*":
        dp[0][j] = dp[0][j - 1]
```
两个case：
1. if (s[m] == p[n] or p[n] == "?"):
    dp[i][j] = dp[i-1][j-1]
2. elif p[n] == "*":
    dp[i][j] = dp[i-1][j] or dp[i][j-1]
dp[i-1][j]表示*取1个或多个，则s最后一个被消除
dp[i][j-1]表示*取0个，则p消除最后一个（*）
```
for i in range(1, len_s + 1):
    for j in range(1, len_p + 1):
        m,n = i-1, j-1
        if (s[m] == p[n] or p[n] == "?"):
            dp[i][j] = dp[i-1][j-1]
        elif p[n] == "*":
            dp[i][j] = dp[i-1][j] or dp[i][j-1]

return dp[-1][-1]
```

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        len_s = len(s)
        len_p = len(p)
        dp = [[False] * (len_p+1) for _ in range(len_s+1)]
        dp[0][0] = True
        # for i in range(1, len_p):
        #     if p[i-1] == p[i] and (p[i] == '*' or p[i]=='?'):
        for j in range(1, len_p + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 1]
        for i in range(1, len_s + 1):
            for j in range(1, len_p + 1):
                m,n = i-1, j-1
                if (s[m] == p[n] or p[n] == "?"):
                    dp[i][j] = dp[i-1][j-1]
                elif p[n] == "*":
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]

        return dp[-1][-1]

        # sn = len(s)
        # pn = len(p)
        # dp = [[False] * (pn + 1) for _ in range(sn + 1)]
        # dp[0][0] = True
        # for j in range(1, pn + 1):
        #     if p[j - 1] == "*":
        #         dp[0][j] = dp[0][j - 1]

        # for i in range(1, sn + 1):
        #     for j in range(1, pn + 1):
        #         if (s[i - 1] == p[j - 1] or p[j - 1] == "?"):
        #             dp[i][j] = dp[i - 1][j - 1]
        #         elif p[j - 1] == "*":
        #             dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
        # return dp[-1][-1]

```