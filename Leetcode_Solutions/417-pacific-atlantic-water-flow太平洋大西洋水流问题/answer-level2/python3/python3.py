```
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if matrix == []: return []
        raw = len(matrix)
        column = len(matrix[0])
        record = [[0 for _ in range(column)] for _ in range(raw)]
        res = []

        def dfs(r, c, water):   # 用00表示没有海水，10表示太平洋，01表示大西洋，11表示都有
            if record[r][c] in [water, 3]: return # 如果[r,c]以及倒灌入了这个海水了，代表dfs过了这个格子，跳过
            record[r][c] |= water   # 将海水灌入[r,c]格子
            for d in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                if r + d[0] < 0 or c + d[1] < 0 or r + d[0] > raw-1 or c + d[1] > column-1:
                    continue
                elif matrix[r+d[0]][c+d[1]] >= matrix[r][c]: # 水往高处流，dfs下个高地
                    dfs(r+d[0], c+d[1], water)
        
        for r in range(raw): # 遍历太平洋沿岸
            dfs(r, 0, 1)
            dfs(r, column-1, 2)
        for c in range(column): # 遍历大西洋沿岸
            dfs(0, c, 1)
            dfs(raw-1, c, 2)
        for r in range(raw): # 找到可以被两个海水都倒灌的陆地
            for c in range(column):
                if record[r][c] == 3:
                    res.append([r, c])
        return res
```
可以理解为水往高处流以后，海水倒灌，太平洋和大西洋的水都能倒灌进的陆地有哪些。
遍历四条与大洋交接的边，dfs即可
