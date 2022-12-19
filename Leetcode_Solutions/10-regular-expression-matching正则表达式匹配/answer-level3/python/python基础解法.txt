### 解题思路
利用动态规划的思想来进行解答，状态表示为dp[i][j]，代表了s的前i个字符是否匹配p的前j个字符
状态转移分为当p[j] 是否等于'*'

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)
        dp = [[False] * (m+1) for i in range(n+1)]
        # 增加无用字符是为了防止边界出界，不影响结果
        s, p = ' '+s, ' '+p
        for i in range(n+1):
            for j in range(m+1):
                dp[0][0] = True
                if j+1 <= m and p[j+1] == '*':
                    continue
                if p[j] != '*':
                    if p[j] == '.' or s[i] == p[j]:
                        if i>0 and j>0:
                            dp[i][j] = dp[i-1][j-1]
                else:
                    if j >= 2:
                        dp[i][j] = dp[i][j-2]
                    if i > 0 and j > 0:
                        if p[j-1] == '.' or s[i] == p[j-1]:
                            if dp[i-1][j]:
                                dp[i][j] = True
        return dp[n][m]

```