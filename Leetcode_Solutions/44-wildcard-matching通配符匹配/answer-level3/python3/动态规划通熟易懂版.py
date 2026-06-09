### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # p分为空不为空讨论3种情况
        if not p :
            if not s :
                return True
            else :
                return False
        else :
            if not s :
                if p == "*" :
                    return True
                else :
                    return False
        # 讨论s,p均不为空的情况
        # 初始化状态列表,使其全为False
        m = len(p) ; n = len(s)
        dp = [[False for j in range(n + 1)] for i in range(m + 1)]
        dp[0][0] = True
        # 当p为空,s不为空时,肯定不能匹配,所以不用计算
        # 当s为空,p不为空时,要分情况进行讨论
        for i in range(1,m + 1):
            if p[i - 1] == "*":
                dp[i][0] = dp[i - 1][0]
            else:
                dp[i][0] = False
        for i in range(1,m + 1) :
            for j in range(1,n + 1) :
                if p[i - 1] == "*" :
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j] or dp[i - 1][j - 1]
                elif p[i - 1] == "?" :
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[i - 1] != "*" and p[i - 1] != "?" and p[i - 1] != s[j - 1]:
                    dp[i][j] = False
                elif p[i - 1] != "*" and p[i - 1] != "?" and p[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
        return dp[m][n]

```