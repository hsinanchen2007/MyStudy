# lalala
```
def hasValidPath(self, grid):
    #  记录可以行走的方向
    dirs = {1:[(0, 1), (0, -1)], 2:[(-1, 0), (1, 0)], 3:[(0, -1), (1, 0)], 4:[(0, 1), (1, 0)], 5:[(0, -1), (-1, 0)], 6:[(0, 1), (-1, 0)]}
    vis = set([(0,0)])
    m, n = len(grid), len(grid[0])
    Q = collections.deque()
    Q.append((0, 0))
    while Q:
        x, y = Q.popleft()
        if x == m-1 and y == n-1:
            return True
        for ndir in dirs[grid[x][y]]:
            tdir = (-1*ndir[0], -1*ndir[1]) # 下一个位置存在对应的方向，表示连通
            nx, ny = x+ndir[0], y+ndir[1]
            if 0<=nx<m and 0<=ny<n and (nx, ny) not in vis and tdir in dirs[grid[nx][ny]]:
                vis.add((nx, ny))
                Q.append((nx, ny))
    return False
```
