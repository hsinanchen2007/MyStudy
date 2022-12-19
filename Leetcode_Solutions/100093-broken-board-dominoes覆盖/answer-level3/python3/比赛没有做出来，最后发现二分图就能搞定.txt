1. 把坏点标记出来，好的点做标记；
2. 上下左右建边；
3. 跑一遍匈牙利

```python
class Solution:
    def __init__(self):
        self.E = [[] for _ in range(65)]
        self.vis = [False for _ in range(65)]
        self.matched = [-1 for _ in range(65)]
        self.tot = 0
        
    def dfs(self, u):
        for nxt in self.E[u]:
            if self.vis[nxt]:
                continue    
            self.vis[nxt] = True
            if self.matched[nxt] == -1 or self.dfs(self.matched[nxt]):
                self.matched[nxt] = u
                return True
        return False
        
    def hungarian(self):
        ans = 0
        for i in range(self.tot):
            self.vis = [False] * 65
            if (self.dfs(i)):
                ans += 1
        return ans        
        
    def domino(self, n: int, m: int, broken: List[List[int]]) -> int:
        flag = [[0] * m for _ in range(n)]
        for b in broken:
            flag[b[0]][b[1]] = -1
            
        cur = 0    
        for i in range(n):
            for j in range(m):
                if flag[i][j] == -1:
                    continue    
                flag[i][j] = cur   
                cur += 1
                
        delta, self.tot = [-1, 0, 1, 0, -1], cur
        for i in range(n):
            for j in range(i % 2, m, 2):
                if flag[i][j] == -1:
                    continue
                for k in range(4):
                    x, y = i + delta[k], j + delta[k + 1]    
                    if x < 0 or y < 0 or x >= n or y >= m or flag[x][y] == -1:
                        continue
                    self.E[flag[i][j]].append(flag[x][y])  

        return self.hungarian()            
    
```