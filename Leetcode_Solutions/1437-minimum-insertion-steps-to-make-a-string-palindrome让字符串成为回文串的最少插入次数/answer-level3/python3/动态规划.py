```
class Solution:
    def minInsertions(self, s: str) -> int:
        """"
        递归：
        判断最左最右是否相同，是则这两个可以匹配，不需要操作，直接消除
        否则，则需要左边/右边插入一个，即只能消除一个，这个时候就要用递归了，看哪中的方法得到的结果更小
        然而，超时

        动态规划：
        dp[i][j]数组，长度为i，以下标j开始的字符串成为回文串所需要的最少插入次数
        状态转化方程：
        dp[i][j] = dp[i-2][j+1] if s[i]==s[j] 左右相同，则直接中间部门的最少插入次数
        dp[i][j] = min(dp[i-1][j],dp[i-1][j+1])+1 左右不同，消除左边一个字符或者右边一个字符，两种情况中最小的结果）
        """
        length = len(s)
        dp = [[0] * length for i in range(2)]
        for i in range(2,length+1):
            tmp = []
            for j in range(0,length+1-i):
                if s[j] == s[j+i-1]:
                    tmp.append(dp[i-2][j+1])
                else:
                    tmp.append(min(dp[i-1][j],dp[i-1][j+1])+1)
            dp.append(tmp)
        return dp[length][0]
        
```
