### 解题思路
执行用时 :140 ms, 在所有 Python 提交中击败了46.50%的用户
内存消耗 :12.7 MB, 在所有 Python 提交中击败了77.14%的用户

### 代码

```python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ext = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        row, col, area = len(grid), len(grid[0]), 0
        islands = []
        maxarea = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    area = 0
                    islands.append((i, j))
                    while islands:
                        area += 1
                        # print(islands, area, [i, j])
                        x, y = islands.pop(0)
                        grid[x][y] = 2
                        for di, dj in ext:
                            if 0 <= x + di < row and 0 <= y + dj < col and (x + di, y + dj) not in islands and \
                                    grid[x + di][y + dj] == 1:
                                islands.append((x + di, y + dj))
                    maxarea.append(area)
        # print(maxarea)
        return max(maxarea) if maxarea else 0       
```