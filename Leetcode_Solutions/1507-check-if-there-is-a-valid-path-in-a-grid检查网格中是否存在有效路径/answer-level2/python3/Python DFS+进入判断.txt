在传统DFS中加入能否进入当前位置的判断，比较简洁。
```py
class Solution:
    def hasValidPath(self, grid):
        import sys   
        sys.setrecursionlimit(100000) # 调整递归限制
        pathDic = {
            1 : [(0, 1), (0, -1)],
            2 : [(1, 0), (-1, 0)],
            3 : [(1, 0), (0, -1)],
            4 : [(1, 0), (0, 1)],
            5 : [(-1, 0), (0 ,-1)],
            6 : [(-1, 0), (0 ,1)]
        } # 每种路径可以选择的下一步方向
        
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        
        # lastd为上一步选择的方向
        def dfs(lastd, x, y):
            if x < 0 or x >= m or y < 0 or y >= n: return False
            if visited[x][y]: return False
            d = pathDic[grid[x][y]]
            if lastd and (-lastd[0], -lastd[1]) not in d: return False # 注意这里，从a进入b要判断能否进入，而从a选择lastd能够进入b的话，lastd的相反方向恰好为b可以选择的离开方向
            if x == m - 1 and y == n - 1: return True
            visited[x][y] = True
            return dfs(d[0], x + d[0][0], y + d[0][1]) or dfs(d[1], x + d[1][0], y + d[1][1])
        
        return dfs(None, 0, 0)
```
