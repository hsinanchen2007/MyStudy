### 解题思路
思路比较简单。
首先，如果道路中出现堵塞，那么该点设置为-1。
两个特异点：初始点被堵塞，还有终点被堵塞，这两点需要单独考虑。
然后，考虑x = 0和y = 0的初始情况。如果x = 0或y = 0的两条线中出现障碍物，那么修改flag1或flag2，影响后续初始化。
然后，考虑dp的情况。如果左边或上边出现-1，那么就不加上该点的路径数。
最后返回dp[m - 1][n - 1]即可。

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        if obstacleGrid[0][0] == 0:
            dp[0][0] = 1
        else:
            return 0
        flag1, flag2 = True, True
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = -1
                    if i == 0:
                        flag1 = False
                    elif j == 0:
                        flag2 = False
                    continue
                if i == 0 and flag1:
                    dp[i][j] = 1
                elif j == 0 and flag2:
                    dp[i][j] = 1
                else:
                    if dp[i - 1][j] == -1 and dp[i][j - 1] == -1:
                        dp[i][j] = 0
                    elif dp[i - 1][j] == -1:
                        dp[i][j] = dp[i][j - 1]
                    elif dp[i][j - 1] == -1:
                        dp[i][j] = dp[i - 1][j]
                    else:                        
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[m - 1][n - 1] if dp[i][j] != -1 else 0
```