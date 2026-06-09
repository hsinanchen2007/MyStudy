```python
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        visited = set()
        def dfs(i, j, color):
            visited.add((i, j))
            flag = True
            for x, y in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]:
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and (x, y) not in visited:
                    if grid[x][y] == grid[i][j] :
                        dfs(x, y, color)
                    else:
                        flag = False
            if i == 0 or i == len(grid) - 1 or j == 0 or j == len(grid[0]) - 1 or not flag:
                grid[i][j] = color
        dfs(r0, c0, color)
        return grid
```