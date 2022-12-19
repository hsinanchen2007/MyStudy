### 解题思路
![image.png](https://pic.leetcode-cn.com/c9455832bba9c0e506dd814430d75810bba5e4d1596b70ae1ffc4227235b8d60-image.png)


### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0

        row = len(obstacleGrid)
        column = len(obstacleGrid[0])

        # 定义一个二维数组,有两种方法:
        # 1. dp = [[0] * column] * row; 这种方法有一种问题: 在对某一个元素赋值时,会导致整列都被赋值
        # 2. dp = [[0] * column for _ in range(row)]
        # 初始化一个row行column列的网格,用于记录到达每个网格的路径数
        dp = [[0] * column for _ in range(row)]

        # 如果第一个网格为障碍物,则直接返回0
        if obstacleGrid[0][0] == 1:
            return 0
        else:
            dp[0][0] = 1

        # 如果只有一行一列,并且网格为障碍物,则返回1
        if row == 1 and column == 1 and obstacleGrid[0][0] == 0:
            return 1

        # 遍历第一列
        for i in range(1, row):
            if obstacleGrid[i][0] == 1:
                dp[i][0] = 0
            elif dp[i - 1][0] == 0:
                dp[i][0] = 0
            else:
                dp[i][0] = 1

        # 遍历第一行
        for i in range(1, column):
            if obstacleGrid[0][i] == 1:
                dp[0][i] = 0
            elif dp[0][i - 1] == 0:
                dp[0][i] = 0
            else:
                dp[0][i] = 1

        for i in range(1, row):
            for j in range(1, column):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        print(dp)
        return dp[row - 1][column - 1]
```