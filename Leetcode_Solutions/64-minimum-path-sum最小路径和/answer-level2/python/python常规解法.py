class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid)==0 or len(grid[0])==0:
            return sum(grid)
        row = len(grid)
        loc = len(grid[0])
        dp = grid
        for i in range(1,row):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for i in range(1,loc):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for i in range(1,row):
            for j in range(1,loc):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]