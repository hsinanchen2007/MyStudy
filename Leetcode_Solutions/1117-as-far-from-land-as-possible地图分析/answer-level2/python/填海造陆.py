
### 代码
```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        #对 0 做 BFS(仅考虑上下左右)，遇到1即返回
        #return max(ManhattanDistance for every 0)
        if not grid:return -1
        row, col = len(grid), len(grid[0])
        dirs = ((1,0),(-1,0),(0,1),(0,-1)) 
        res = 0
        land, ocean = collections.deque(), set()
        for i in range(row):
            for j in range(col):
                if grid[i][j]: land.append((i,j))
                else: ocean.add((i,j))
        if not land or not ocean:return -1
        while land:
            lSize, oSize = len(land), len(ocean)
            for item in range(lSize):
                x, y = land.popleft()
                for dx, dy in dirs:
                    temp = (x+dx, y+dy)
                    if temp in ocean:
                        ocean.remove(temp)
                        land.append(temp)
            res += len(ocean) < oSize
        return res
```