方向搜索的笨办法解题：

```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # 搜索方向
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    area += grid[i][j]*4 + 2
                    # 对每一个有积木的位置搜索他的四个方向，若存在积木则减去公共面积
                    for dirc in directions:
                        new_x = i + dirc[0]
                        new_y = j + dirc[1]
                        if 0 <= new_x and new_x < m and 0 <= new_y and new_y < n and grid[new_x][new_y] > 0:
                            area -= min(grid[new_x][new_y], grid[i][j])
        return area
```

