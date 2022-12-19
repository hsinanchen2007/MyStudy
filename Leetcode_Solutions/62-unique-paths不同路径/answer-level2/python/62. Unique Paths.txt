同64_Minimum Path Sum该题

```
# grid[i][j] = grid[i-1][j] + grid[i][j-1]

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == 1 or n == 1:
            return 1
        grid = [[0 for _ in range(n)] for _ in range(m)]
        grid[0][1], grid[1][0] = 1, 1
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                elif i == 0 and j > 0:
                    grid[i][j] += grid[i][j-1]
                elif i > 0 and j == 0:
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] = grid[i-1][j] + grid[i][j-1]
        return grid[-1][-1]
print Solution().uniquePaths(3,2)        
```
