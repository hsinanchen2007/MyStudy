### 解题思路
一圈一圈往外腐蚀

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        rotlist = list()    # 腐烂橘子的队列
        minute = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    rotlist.append([i, j])

        while rotlist:  # BFS循环
            newrotlist = list()
            for rotorange in rotlist:   # 当前腐烂橘子的坐标
                x0 = rotorange[0]
                y0 = rotorange[1]

                for i in range(4):  # 四个相邻方向的橘子腐烂
                    x = x0 + dx[i]
                    y = y0 + dy[i]
                    if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y]==1:
                        grid[x][y] = 2
                        newrotlist.append([x, y])

            if not newrotlist:
                break

            minute += 1
            rotlist = newrotlist[:]     # 更新腐烂队列

        for row in grid:
                for i in row:
                    if i == 1:  # 还有新鲜的
                        return -1

        return minute




```