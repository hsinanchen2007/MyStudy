```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # 只能从上或者从左到达某个路径。
        # 所以DP[i][j] = grid[i][j] + min(DP[i-1][j],DP[i][j-1])
        # 初始化是第一列和第一行，只能向下或者向右
        row = len(grid)
        column = len(grid[0])
        dp = [[None]* column for i in range(row)]
        rowsum=0
        for j in range(0,column):
            rowsum += grid[0][j]
            dp[0][j] = rowsum
        columnsum=0
        for i in range(0,row):
            columnsum += grid[i][0]
            dp[i][0] = columnsum
        for i in range(1,row):
            for j in range(1,column):
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1])
        return dp[row-1][column-1]
```
