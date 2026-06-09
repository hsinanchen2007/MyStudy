### 解题思路
This is suitable for the beginers ! 

### 代码

```python3
class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        count = 0 
        move_x, move_y = [1,0,-1,0], [0,1,0,-1]
        for i in range(len(grid)):
            for w in range(len(grid[0])):
                if grid[i][w] == '0':
                    temp = 0
                    for x in range(4):
                        row, col = i, w
                        while row >= 0 and row < len(grid) and col >= 0 and col < len(grid[0]) and grid[row][col] != 'W':                     
                            if grid[row][col] == 'E':
                                temp += 1
                            row += move_x[x]
                            col += move_y[x]
                    count = max(count, temp)
        return count
```