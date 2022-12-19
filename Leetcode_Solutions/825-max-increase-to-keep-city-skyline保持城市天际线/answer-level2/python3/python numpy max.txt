class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        import numpy as np
        grid = np.array(grid)
        ver = grid.max(axis=0)
        hor = grid.max(axis=1)
        diff = 0
        for i in range(grid.shape[0]):
            for j in range(grid.shape[1]):
                diff += min(ver[i], hor[j]) - grid[i,j]
                
        return diff