先后通过大西洋和太平洋的逆流来确定它们共同的边界，这些共同的边界就是所求的点。先从太平洋逆流，流过的地方标记为1， 再从大西洋逆流，流过的地方标记为-1，但是，如果遇到1，说明他就是边界，把它标记为3，并沿着它继续找边界。

```
def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(matrix) == 0:
            return []
        self.r, self.c = len(matrix), len(matrix[0])
        self.res = set([])
        if self.r == 1 or self.c == 1:
            for r in range(0, self.r):
                for c in range(0, self.c):
                    self.res.add((r, c))
            return self.res
        self.unvisited = [[0 for _ in range(self.c)] for _ in range(self.r)]
        self.d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        def inArea(r,c):
            return r>=0 and r<self.r and c>=0 and c<self.c

        def flow(r, c, v, vt):
            if self.unvisited[r][c] == 0:
                self.unvisited[r][c] = v
                for i in range(4):
                    rt = r + self.d[i][0]
                    ct = c + self.d[i][1]
                    if inArea(rt, ct) and matrix[rt][ct] >= matrix[r][c] and self.unvisited[rt][ct] != v:
                        flow(rt, ct, v, vt)              
            elif self.unvisited[r][c] == vt:
                self.res.add((r,c))
                self.unvisited[r][c] = self.B
                for i in range(4):
                    rt = r + self.d[i][0]
                    ct = c + self.d[i][1]
                    if inArea(rt, ct) and matrix[rt][ct] >= matrix[r][c] and self.unvisited[rt][ct]==vt:
                        flow(rt, ct, v, vt)

        self.B, P, W = 3, 1, -1
        #左上
        for c in range(self.c):
            flow(0, c, P, W)            
        for r in range(1, self.r):
            flow(r, 0, P, W)
        #右下            
        for r in range(self.r):
            flow(r, self.c-1, W, P)
        for c in range(self.c):
            flow(self.r-1, c, W, P)

        return self.res
```

