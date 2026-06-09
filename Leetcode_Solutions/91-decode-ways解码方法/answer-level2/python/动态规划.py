# 当前位与前一位形成的两位数
# 0 - 9:dp[i] = dp[i - 1]
# 10, 20:dp[i] = dp[i - 2]
# 11 - 19, 21 - 26:dp[i] = dp[i - 1] + dp[i - 2] 
# 26+:return 0

```
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        lens = len(s)
        # 空串返回0
        if lens == 0:
            return 0
        # 第一个数字为0返回0
        if s[0] == '0':
            return 0

        dp = [0 for _ in range(lens + 1)]
        dp[0] = 1
        dp[1] = 1
        for i in range(1, lens):
            temp = int(s[i - 1 : i + 1])
            if int(s[i]) > 0:
                dp[i + 1] = dp[i]
            if temp > 9 and temp < 27:
                dp[i + 1] = dp[i + 1] + dp[i - 1]
            if dp[i + 1] == 0:
                return 0 
        return dp[lens]
```
