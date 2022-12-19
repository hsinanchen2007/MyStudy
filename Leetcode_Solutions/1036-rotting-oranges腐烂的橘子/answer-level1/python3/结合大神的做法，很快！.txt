### 解题思路
思路就官方题解思路，但实现更好理解。


### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        x, y, time = len(grid), len(grid[0]), 0
        locs = [[-1,0],[0,-1],[0,1],[1,0]]
        deque = collections.deque()

        for i in range(x):
            for j in range(y):
                if grid[i][j] == 2:
                    deque.append((i, j, 0))
        while deque:  
            i, j, time = deque.popleft()
            for loc in locs:
                loc_i, loc_j = i+loc[0], j+loc[1]
                if 0 <= loc_i < x and 0 <= loc_j < y and grid[loc_i][loc_j] == 1:
                    grid[loc_i][loc_j] = 2
                    deque.append((loc_i, loc_j, time+1))

        if any(1 in row for row in grid):
            return -1
            
        return time
        
```