以为是个滑动窗口题，原来是一个动态规划题。

和76题的区别在于，一个是子串，一个是子序列。

DP(i,j)表示T[:i]和S[:j]满足题意时S中的起始index，也就是子串W的位置为S[index:j]，index = DP(i,j)

所以就有递归方程：if T[i] == S[j]:DP(i,j) = DP(i-1,j-1)
                else:DP(i,j) = DP(i,j-1)

初始化：DP(i,j):if i == 0: DP(0,j) = j
                if j == 0:  DP(i,0) = 0

由于题目要求的是子序列，所以需要得到起始位置和长度，还是最小窗口的。
也就是min(j-dp(len(T),j))，然后逐步更新即可。

```
class Solution(object):
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        m = len(T)
        n = len(S)
        dp = [[0] * (n+1) for _ in range(m+1)]
        for j in range(n+1):
            dp[0][j] = j + 1
            
        for i in range(1,m+1):
            for j in range(1,n+1):
                if T[i-1] == S[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i][j-1]
        
        start = 0
        l = n+1
        for j in range(1,n+1):
            if dp[m][j] :
                if j - dp[m][j] + 1 < l:
                    start = dp[m][j]-1
                    l = j - dp[m][j] + 1
        return "" if l == n+1 else S[start:start+l]
```
