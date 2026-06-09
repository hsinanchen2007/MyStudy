### 解题思路
思路很简单，就是需要注意一下第一行和第一列的初始化，只要碰到一个1，后面的全是1，
代码只是看着多，但是只是多了一个初始化而已，可以简写的，为了清晰没有简写。
这里只贴出优化过后的代码，未优化的太简单了，
### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid == None or obstacleGrid[-1][-1] == 1 or obstacleGrid[0][0] == 1:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = []
        for i in range(len(obstacleGrid[0])):
            if obstacleGrid[0][i] == 0:
                dp.append(1)
            else:
                for j in range(i, len(obstacleGrid[0])):
                    dp.append(0)
                break
        left = []
        for i in range(len(obstacleGrid)):
            if obstacleGrid[i][0] == 0:
                left.append(1)
            else:
                for j in range(i, len(obstacleGrid)):
                    left.append(0)
                break
        for i in range(1,m):
            dp[0] =  left[i]
            for j in range(1,n):
                if obstacleGrid[i-1][j] == 1:
                    dp[j] = 0
                if obstacleGrid[i][j-1] == 1:
                    dp[j-1] = 0
                dp[j] = dp[j-1] + dp[j]
        return dp[-1]
```