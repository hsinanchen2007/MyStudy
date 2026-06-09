### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # bfs
        if not grid: return -1
        m, n = len(grid), len(grid[0])
        mark = [[0 for i in range(n)] for i in range(m)]
        Hash = {}
        for i in range(m):
            for j in range(n):
                if grid[i][j] in Hash:
                    Hash[grid[i][j]].append([i, j])
                else:
                    Hash[grid[i][j]] = [[i, j]]

        if 1 not in Hash: return 0
        if 2 not in Hash: return -1

        q = [coord for coord in Hash[2]]
        res = 0
        while q:
            for _ in range(len(q)):
                x, y = q.pop(0)
                nexts = [[x-1, y], [x+1, y], [x, y-1], [x, y+1]]
                for next in nexts:
                    x, y = next
                    if 0 <= x < m and 0 <= y < n:
                        if grid[x][y] == 1:
                            grid[x][y] = 2
                            q.append(next)
                            Hash[1].pop()
            res += 1
        print(Hash)
        if 1 in Hash and len(Hash[1]) > 0: return -1
        return res-1
            
            


```