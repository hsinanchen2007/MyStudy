因为钥匙很少，自然而然就想到状态，所以在染色数组中增加一个钥匙的维度，每次获得钥匙之后之前的路可以继续进入广搜。
这题没有任何坑，把状压写出来基本就 ok 了！
1 A 掉

```python
class Solution:
    def __init__(self):
        self.asc = { 'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, }
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, -1, 1]
        
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        sx, sy, ks = -1, -1, 0
        vis = [[[None for _ in range(1 << 6)] for _ in range(n)] for _ in range(m)]
        
        # 预处理
        for i in range(m):
            for j in range(n):
                ch = grid[i][j]
                if ch == '@':
                    sx, sy = i, j
                    vis[i][j][0] = True
                elif ch >= 'a' and ch <= 'f':
                    ks |= (1 << self.asc[ch])    
                    
        res = 0 
        q = collections.deque()
        q.append((sx, sy, 0, 0))
        while q:
            x, y, k, st = q.popleft()
            #print(x, y, k)
            if k == ks:     
                return st
            for i in range(4):
                nx, ny = x + self.dx[i], y + self.dy[i]
                nk = k
                # 边界处理
                if nx < 0 or nx >= m or ny < 0 or ny >= n:     
                    continue
                # 墙壁判断    
                ch = grid[nx][ny]
                if ch == '#':
                    continue
                # 遇到门但是没有钥匙 
                if ch >= 'A' and ch <= 'F' and nk & (1 << self.asc[ch.lower()]) == 0:
                    continue
                # 找到一个钥匙修改 nk    
                if ch >= 'a' and ch <= 'f':
                    nk |= (1 << self.asc[ch])
                # 染色剪枝    
                if vis[nx][ny][nk]:
                    continue
                q.append((nx, ny, nk, st + 1))
                vis[nx][ny][nk] = True
                
        return -1        
        
```