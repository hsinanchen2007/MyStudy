class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # m row=3, n col=7
        grid = [[0]*n]*(m+1)
        grid[1][0] = 1  # 第2行第一个值是1
        for i in range(1, m+1):
            for j in range(1, n):
                grid[i][j] = grid[i-1][j] + grid[i][j-1]
        return grid[m][n-1]