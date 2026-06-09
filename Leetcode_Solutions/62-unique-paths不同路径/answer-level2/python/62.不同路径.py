(1)定义数组元素的含义

dp[i][j] : 机器人走到这个位置时的所有不同的路径
dp[m-1][n-1] : 求解的答案

(2)找关系

要想到达(i,j)这个位置，可以从(i-1,j)、(i,j-1)到达
那么：
dp[i][j] = dp[i-1][j] + dp[i][j-1]

(3)定义初始值

当i、j有一个0时，状态方程下标会出现负值
所以初始值必须定义：
dp[0][0...n-1] = 1; 一直往右走，只有一种走法
dp[0...m-1][0] = 1; 一直往下走，只有一种走法

```
class Solution(object):
    def uniquePaths(self, m, n):
        dp = [[0]*n for i in range(m)] 
        dp[0][0] = 1
        for i in range(1,m):
            dp[i][0] = dp[i-1][0]   #或为1
        for j in range(1,n):
            dp[0][j] = dp[0][j-1]  #或为1

        
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
```
