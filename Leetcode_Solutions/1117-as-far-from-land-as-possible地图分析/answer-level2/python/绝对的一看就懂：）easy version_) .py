### 解题思路
1. Try to find the location of each island
2. if there is no land or water in this grid, return -1 
3. we just use while loop till all elements would be droped off
4. inside the while loop, we could use for loop to look though all directions and redefine these values

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        result = []
        for i in range(m):
            for w in range(n):
                if grid[i][w] == 1:
                    result.append((i,w))
                else:
                    grid[i][w] = 0      
        if len(result) == 0 or len(result) == m * n:
            return -1
        count = 0
        while result:
            count += 1  
            for i in range(len(result)):
                x, y = result.pop(0)
                if x + 1 < m and grid[x+1][y] == 0:
                    result.append((x+1, y))
                    grid[x+1][y] = -1
                if x - 1 >= 0 and grid[x-1][y] == 0:
                    result.append((x-1, y))
                    grid[x-1][y] = -1
                if y + 1 < n and grid[x][y+1] == 0:
                    result.append((x, y+1))
                    grid[x][y+1] = -1
                if y - 1 >= 0 and grid[x][y-1] == 0:
                    result.append((x, y-1))
                    grid[x][y-1] = -1
        return count - 1

```