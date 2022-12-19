广度优先搜索，每一步都按照原来格子的方向走完所有的地方。

下一步从上一步的边缘，访问任何相邻但是没有访问过的格子



```python
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        # 1 ，下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
        # 2 ，下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
        # 3 ，下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
        # 4 ，下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
        n = len(grid)
        m = len(grid[0])
        mp = [[False] *m for _ in range(n)]
        def step(x, y):
            l = set()
            while 0 <= x < n and 0 <= y < m:
                if (x, y) in l or mp[x][y]:
                    break
                mp[x][y] = True
                l.add((x, y))
                if (x, y) == (n-1, m-1): return l
                if grid[x][y] == 1:
                    y += 1
                elif grid[x][y] == 2:
                    y -= 1
                elif grid[x][y] == 3:
                    x += 1
                elif grid[x][y] == 4:
                    x -= 1
            return l
        s1 = step(0, 0)
        if (n-1, m-1) in s1:
            return 0
        d = 0
        while True:
            ss = set()
            for x, y in s1:
                dr = [[0, 1], [1,0], [-1, 0], [0, -1]]
                for xd, yd in dr:
                    xx = x + xd
                    yy = y + yd
                    if 0<= xx < n and 0 <= yy < m and not mp[xx][yy]:
                        s2 = step(xx, yy)
                        if (n-1, m-1) in s2:
                            return d + 1
                        ss = ss.union(s2)
            s1 = ss
            d += 1
        return 
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)