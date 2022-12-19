### 解题思路
总共的面减去接触面

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        cubes = 0
        faces = 0
        for i in range(n):
            for j in range(n):
                cubes += grid[i][j]
                if grid[i][j] > 0:
                    faces += grid[i][j] -1
                if i > 0:
                    faces += min(grid[i-1][j], grid[i][j])
                if j > 0:
                    faces += min(grid[i][j-1], grid[i][j])
        return 6*cubes - 2 *faces
```