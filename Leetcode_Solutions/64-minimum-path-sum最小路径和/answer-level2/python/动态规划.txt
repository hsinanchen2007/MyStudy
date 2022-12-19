## 自顶向下

核心点：grid[rows][columns] += min(grid[rows][columns + 1], grid[rows + 1][columns])

```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        columns = len(grid[0]) - 1
        while columns >= 0:
            rows = len(grid) - 1
            while rows >= 0:
                if columns == len(grid[0]) - 1:
                    if rows != len(grid) - 1:
                        grid[rows][columns] += grid[rows + 1][columns]
                else:
                    if rows == len(grid) - 1:
                        grid[rows][columns] += grid[rows][columns + 1]
                    else:
                        grid[rows][columns] += min(grid[rows][columns + 1], grid[rows + 1][columns])
                rows -= 1
            columns -= 1
        return grid[0][0]
```

核心点：grid[rows][columns] += min(grid[rows][columns - 1], grid[rows - 1][columns])

## 自底向上
```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for rows in range(len(grid)):
            for columns in range(len(grid[0])):
                if rows == 0:
                    if columns != 0:
                        grid[rows][columns] += grid[rows][columns - 1]
                else:
                    if columns == 0:
                        grid[rows][columns] += grid[rows - 1][columns]
                    else:
                        grid[rows][columns] += min(grid[rows][columns - 1], grid[rows - 1][columns])
        return grid[-1][-1]
```
