```
def maxDistance(grid):
    if not grid:
        return -1
    queue = []
    dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

    m = len(grid)
    n = len(grid[0])
    level = 1          
    for i in range(m):
        for j in range(n):
            if grid[i][j]:
                queue.append((i, j, level))       #将所有陆地坐标加入队列，level - 1表示该坐标距离陆地的距离

    while queue:
        tmp = []
        for _ in range(len(queue)):
            x, y, level = queue.pop(0)
            for dir in dirs:
                dx = dir[0]
                dy = dir[1]
                if 0 <= x + dx < m and 0 <= y + dy < n and not grid[x + dx][y + dy]:
                    grid[x + dx][y + dy] = 1
                    tmp.append((x+dx, y+dy, level + 1))
        queue = tmp
        res = level
    if level == 1:       # level=1表示全是陆地或者全是水
        return -1
    else:
        return res - 1
```
