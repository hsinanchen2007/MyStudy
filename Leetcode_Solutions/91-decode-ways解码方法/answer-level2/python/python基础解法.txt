### 解题思路
使用动态规划的方法来做，主要是确定一些边界问题，类似爬楼梯，dp[i] = dp[i-1] + dp[i-2],利用最后一个字母的时候不能等于0，利用最后两个字母的时候需要I>=2，同时大于等于10，小于等于26

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0]* (n+1)
        dp[0] = 1
        for i in range(1, n+1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if i >= 2:
                num = int(s[i-2]) * 10 + int(s[i-1])
                if 26 >= num >= 10:
                    dp[i] += dp[i-2]
        return dp[n]

```