```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        nodes = [(i, j) for i in range(m) for j in range(n) if grid[i][j]]
        if not nodes or len(nodes)==m*n:#是否为纯陆地或纯海洋
           return -1
        
        def isValid(x, y):#判断给定坐标是否有效
            return 0<= x <m and 0<= y <n
        
        depth = -1
        delt = [(0,1),(0,-1),(1,0),(-1,0)]
        while nodes:#处理当前层信息
            depth += 1
            tmp = []#存储待探索海洋坐标
            for x, y in nodes:#对当前每个待探坐标分别处理4个方向
                for d in delt:
                    newx, newy = x+d[0], y+d[1]
                    if isValid(newx, newy) and not grid[newx][newy]:#新点是海洋且未探测
                        tmp.append((newx, newy))
                        grid[newx][newy] = 1
            nodes = tmp
        return depth
```
