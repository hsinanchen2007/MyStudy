这道题是一个经典的动态规划问题，定义dp[i][j] 表示执行i步时，在第j个索引的位置的走法数，该位置可以由三种情况获得dp[i-1][j]的位置不动，dp[i-1][j-1]的位置向右移动，以及dp[i-1][j+1]的位置向左移动；即：
dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]，再配合一些边界判断即可；
注意：1. 当arrLen > steps时无需判断，因为不可能到达；
      2. 本题还可以优化的点，dp矩阵的右下角的半边都不需要； 
代码如下：

```
class Solution(object):
    def numWays(self, steps, arrLen):
        """
        :type steps: int
        :type arrLen: int
        :rtype: int
        """
        
        
        if steps < arrLen:
            arrLen = steps
        dp = [[0]*arrLen for i in range(steps + 1)]
        dp[0][0] = 1
        if steps == 0:
            return 1
        for i in range(1,steps+1):
            for j in range(arrLen):
                if j == 0 and j == arrLen - 1:
                    dp[i][j] = dp[i-1][j] 
                elif j == 0 :
                    dp[i][j] = dp[i-1][j] + dp[i-1][j+1]
                elif j == arrLen - 1:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]
        # print(dp)
        return dp[steps][0] % (1000000000 + 7)
                    
```
