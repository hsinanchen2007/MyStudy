解法：动态规划，dp = df[i-1] + dp[i-2]，如果前一位字符和当前字符能组成[10,26]之间的数，即int(s[i-2:i])，则加上dp[i-2]；当前字符大于0，即int(s[i-1])，则加上dp[i-1]

时间复杂度：O(n)
```
class Solution(object):
    def numDecodings(self, s):
        if s == '0':
            return 0
        # 构造一个n+1 长度的数组
        dp = [0] * (len(s) + 1)
        # 为了第二个元素方便计算
        dp[0] = 1
        # 代表第一个元素
        dp[1] = int(s[0] != '0')

        for i in range(2, len(s)+1):
            # 思路 dp = df[i-1] + dp[i-2]
            # 如果前一位字符和当前字符，即int(s[i-2:i])，能组成[10,26]之间的数，则加上dp[i-2]
            # 当前字符int(s[i-1])，大于0，即则加上dp[i-1]
            dp[i] = dp[i-2] * int(9 < int(s[i-2:i]) < 27) + dp[i-1] * int(int(s[i-1]) > 0)
        return dp[-1]
```
