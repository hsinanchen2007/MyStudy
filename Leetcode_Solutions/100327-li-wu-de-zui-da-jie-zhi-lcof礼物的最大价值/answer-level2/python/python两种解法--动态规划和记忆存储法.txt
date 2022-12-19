1.动态规划 
这次用的方法不需要额外的存储空间,直接在原数组上进行修改
时间复杂度O(m*n),空间复杂度O(1)

```python
class Solution(object):
    def maxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j == 0:
                    continue
                if i == 0 and j >= 1:
                    grid[i][j] = grid[i][j-1] + grid[i][j]
                elif j == 0 and i >= 1:
                    grid[i][j] = grid[i-1][j] + grid[i][j]
                else:
                    A = grid[i-1][j] + grid[i][j]
                    B = grid[i][j-1] + grid[i][j]
                    grid[i][j] = max(A, B)
        return grid[len(grid)-1][len(grid[0])-1]


```
2.记忆存储
```
#记忆存储法
class Solution(object):
    def maxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return None
        value = [[-1]*(len(grid[0])) for i in range(len(grid))]
        return self.maxCore(grid, len(grid)-1, len(grid[0])-1, value)

    def maxCore(self, grid, i , j, value):
        if value[i][j] != -1:
            return value[i][j]
        if i == 0 and j == 0:
            return grid[0][0]
        elif i == 0:
            return self.maxCore(grid, i, j-1, value) + grid[i][j]
        elif j == 0:
            return self.maxCore(grid, i-1, j, value) + grid[i][j]
        else:
            A = self.maxCore(grid, i-1, j, value) + grid[i][j]
            B = self.maxCore(grid, i, j-1, value) + grid[i][j]
            value[i][j] = max(A, B)
            return max(A, B)


```

