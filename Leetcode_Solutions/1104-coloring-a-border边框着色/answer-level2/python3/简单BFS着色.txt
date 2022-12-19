
-   从目标点开始层次遍历
-   关键在于判断当前点是否需要着色：
    -   在边界
    -   周围有不同与目标颜色的点

满足上面两个条件的就进行着色



```python
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        row, col = len(grid), len(grid[0])
        visited = [[0 for _ in range(col)] for _ in range(row)]
        target_color = grid[r0][c0]
        surround = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        d = [[r0, c0]]

        # 坐标验证
        def available(m, n):
            return 0 <= m < row and 0 <= n < col

        while d:
            next_d = []
            for x, y in d:
                visited[x][y] = 1
                for dx, dy in surround:
                    x1, y1 = x + dx, y + dy
                    if available(x1, y1):
                        if not visited[x1][y1]:
                            if grid[x1][y1] == target_color:
                                next_d.append([x1, y1])
                            else:
                                grid[x][y] = color

                    else:
                        grid[x][y] = color
            d = next_d

        return grid
```


