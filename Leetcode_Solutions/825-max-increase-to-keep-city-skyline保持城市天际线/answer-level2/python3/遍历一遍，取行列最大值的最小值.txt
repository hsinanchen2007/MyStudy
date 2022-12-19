```
class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rs=0
        for i in range(grid.__len__()):
            for j in range(grid[0].__len__()):
                # rs=rs+abs(grid[i][j]-min(max(grid[i][:]),max(grid[:][j])))

                row_max=max(grid[i])
                col_max=max([item[j] for item in grid])
                rs=rs+abs(grid[i][j]-min(row_max,col_max))
        return rs
```
