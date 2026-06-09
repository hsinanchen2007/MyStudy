### 解题思路

dp[i][j] = k 串s前i个字符可以最多组合成k个串t前j个字符
            解释一下递推式子:
            
            s[i] != t[j]
                dp[i][j] = dp[i-1][j]
                这种情况很好解释，s[i]不能与t[j] 匹配，那么只能祈求s[1 - (i-1)]与t[1 - j]能够匹配成功，
                自然前面组合的次数就是我当前组合的次数。
            s[i] == t[j]:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
                该情况分为两部分:
                第一部分：dp[i-1][j]可以参考为s[i] != t[j]情况的解释，也可以理解为，s[i]不参与组合，直接等于
                前面的组合情况
                第二部分：s[i]参与组合，即s[i]与t[j]匹配，那么s[1-(i-1)] 与 t[1-(j-1)]去匹配，自然dp[i][j] = dp[i-1][j-1]


### 代码

```python3
class Solution:
    def numDistinct(self, s: str, t: str):
        l1 = len(s)
        l2 = len(t)
        dp = [[0]*(l2+1) for _ in range(l1+1)]
        for i in range(l1+1):
            dp[i][0] = 1
        for i in range(1,l1+1):
            for j in range(1,l2+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[-1][-1]


```

