### 解题思路
1.若s[0]='0',则return 0
2.设dp[i]表示从0~i共有dp[i]种解法 dp[i]的确定如下所述:
*若s[i] = 0,当s[i-1]等于 1 或 2 时，dp[i] = dp[i-2],否则，return 0
*若s[i]!= 0,当s[i-1] = 1 或 s[i-1] = 2 且 s[i] = 1~6 时，dp[i] = dp[i-1] + dp[i-2],其余情况
dp[i] = dp[i-1]

### 代码

```python
class Solution(object):
    def numDecodings(self, s):
        if not s or s[0] == '0':
            return 0
        if len(s) == 1 and s[0] != '0':
            return 1
        if len(s) >= 2:
            dp = [0]*len(s)
            dp[0] = 1
            if s[1] == '0':
                if 1 <= int(s[0]) <= 2:
                    dp[1] = 1
                else:
                    return 0
            else:
                if s[0] == '1':
                    dp[1] = 2
                elif s[0] == '2' and 1 <= int(s[1]) <= 6:
                    dp[1] = 2
                else:
                    dp[1] = 1
            for i in range(2,len(s)):
                if s[i] == '0':
                    if 1 <= int(s[i-1]) <= 2:
                        dp[i] = dp[i-2]
                    else:
                        return 0
                else:
                    if s[i-1] == '1':
                        dp[i] = dp[i-1] + dp[i-2]
                    elif s[i-1] == '2' and 1 <= int(s[i]) <= 6:
                        dp[i] = dp[i-1] + dp[i-2]
                    else:
                        dp[i] = dp[i-1]
            return dp[-1]
            
```