dp[i] = dp[i-1]×（第i个单独解码个数） + dp[i-2]×（第i-1和i个一起解码的个数）
就是分类个数有点多.
```
class Solution:
    def numDecodings(self, s: str) -> int:
        def init(x): #初始化dp[1]
            if x[0] == '0':
                return 0
            elif x[0] == '*' and x[1] == '*':
                return 96
            elif x[0] == '*' and int(x[1]) == 0:
                return 2
            elif x[0] == '*' and int(x[1])<=6:
                return 11
            elif x[0] == '*' and int(x[1])>=7:
                return 10
            elif x[1] == '*' and int(x[0]) == 1:
                return 18
            elif x[1] == '*' and int(x[0]) == 2:
                return 15
            elif x[1] == '*' and int(x[0]) >= 3:
                return 9
            elif int(x[0]) >= 3 and int(x[1]) ==0:
                return 0
            elif int(x[0]) <= 3 and int(x[1]) == 0:
                return 1
            elif int(x) >=27:
                return 1
            else:
                return 2
        def twoNumDecodings(x): #两个字符联合解码
            if x[0] == '0':
                return 0
            elif x[0] == '*' and x[1] == '*':
                return 15
            elif x[0] == '*' and int(x[1])<=6:
                return 2
            elif x[0] == '*' and int(x[1])>=7:
                return 1
            elif x[1] == '*' and int(x[0]) == 1:
                return 9
            elif x[1] == '*' and int(x[0]) == 2:
                return 6
            elif x[1] == '*' and int(x[0]) >= 3:
                return 0
            elif int(x[0]) >= 3 and int(x[1]) == 0:
                return 0
            elif int(x[0]) <= 2 and int(x[1]) == 0:
                return 1
            elif int(x) <= 26:
                return 1
            else:
                return 0
            
        n = len(s)
        if s == '0':
            return 0
        if n == 1:
            return 9 if s[0] == '*' else 1
        dp = [0] * n
        if s[0] == '*':
            dp[0] = 9
        elif s[0] == '0':
            dp[0] = 0
        else:
            dp[0] = 1
        dp[1] = init(s[:2])
        for i in range(2,n):
            if s[i] == '0' and s[i-1] =='0': # '00'无法解码，提前返回
                return 0
            if s[i] == '*':
                dp[i] = dp[i-1] * 9
            elif s[i] != '0':
                dp[i] = dp[i-1]
            dp[i] += dp[i-2] * twoNumDecodings(s[i-1:i+1])
            dp[i] = dp[i] % (10**9+7)
        return dp[-1]
```
