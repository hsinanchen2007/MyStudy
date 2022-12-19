### 解题思路
暴力方法，直接遍历
- 周长统计的时候，需要查看上下左右四周的网格
- 若在网格边缘，则直接统计；
- 若周围网格是水域，则进行统计；
- 若周围网格是陆地，则不进行统计；

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        if rows == 0:
            return 0
        cols = len(grid[0])
        cnt = 0
        direction = [(-1,0), (1,0), (0,-1), (0,1)]  # top,bottom,left,right
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] < 1:
                    continue
                for (mx, my) in direction:
                    new_x = i + mx
                    new_y = j + my
                    # 边缘网格统计
                    if new_x < 0 or new_x >= rows:
                        cnt += 1
                    elif new_y < 0 or new_y >= cols:
                        cnt += 1
                    elif grid[new_x][new_y] == 0:
                        cnt += 1
        return cnt
                
```