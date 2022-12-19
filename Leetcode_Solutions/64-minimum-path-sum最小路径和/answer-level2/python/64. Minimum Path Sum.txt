总结的公式: 
`grid[i,j] += min(grid[i-1,j], grid[i,j-1])`
画个图, 就能明白该公式了, 当前值的累加, 只有两种情况 (跟爬楼梯问题一样的, 当前能达到该点的状态是什么)
但是需要考虑到边际值的问题:
i,j同时为0, continue;
i,j有其中一个值为0情况, 仅累加一方值;
else: grid[i,j] += min(grid[i-1,j], grid[i,j-1])

```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j == 0:
                    continue
                if i == 0 and j > 0:
                    grid[i][j] += grid[i][j-1]
                elif i != 0 and j == 0:
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]
```
