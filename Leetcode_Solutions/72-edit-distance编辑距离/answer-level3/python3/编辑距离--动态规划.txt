思路见注释：

```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m,n = len(word1)+1,len(word2)+1 #扩充一个单位初始化 得到(m+1)x(n+1)的矩阵
        dp = [[0]*n for i in range(m)] #m做列，n做行 m*n
        for x in range(m): #初始化列数据
            dp[x][0] = x
        for y in range(n): #初始化行数据
            dp[0][y] = y        
        for i in range(1,m):
            for j in range(1,n):
                if word1[i-1] == word2[j-1]:dp[i][j] = dp[i-1][j-1] #重复字符不变
                else:dp[i][j] = min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1 #区域取极小+1
        return dp[-1][-1]
```
