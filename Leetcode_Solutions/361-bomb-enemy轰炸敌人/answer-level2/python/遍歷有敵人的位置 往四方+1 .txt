### 解题思路
找到敵人的位置 並向上下左右的路線+1
最後累加所有的結果
找到最大值 即可

### 代码

```python3
class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:

        max_v = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == 'E':

                    co_i = i
                    while co_i > -1 and co_i < len(grid):
                        if grid[co_i][j] == 'W':
                            co_i = -1
                        elif grid[co_i][j] == 'E':
                            co_i -= 1  
                        elif grid[co_i][j] != 'E' and grid[co_i][j] != 'E':
                            grid[co_i][j]  = str(int(grid[co_i][j]) + 1) 
                            max_v = max(max_v, int(grid[co_i][j]))
                            co_i -= 1      
                    
                    co_i = i
                    while co_i > -1 and co_i < len(grid):
                        if grid[co_i][j] == 'W':
                            co_i = -1
                        elif grid[co_i][j] == 'E':
                            co_i += 1  
                        elif grid[co_i][j] != 'E' and grid[co_i][j] != 'E':
                            grid[co_i][j] = str(int(grid[co_i][j]) + 1)
                            max_v = max(max_v, int(grid[co_i][j]))
                            co_i += 1 

                    co_j = j
                    while co_j > -1 and co_j < len(grid[0]):
                        if grid[i][co_j] == 'W':
                            co_j = -1
                        elif grid[i][co_j] == 'E':
                            co_j -= 1  
                        elif grid[i][co_j] != 'E' and grid[i][co_j] != 'E':
                            grid[i][co_j]  = str(int(grid[i][co_j]) + 1)
                            max_v = max(max_v, int(grid[i][co_j]))
                            co_j -= 1      

                    co_j = j
                    while co_j > -1 and co_j < len(grid[0]):
                        if grid[i][co_j] == 'W':
                            co_j = -1
                        elif grid[i][co_j] == 'E':
                            co_j += 1  
                        elif grid[i][co_j] != 'E' and grid[i][co_j] != 'E':
                            grid[i][co_j] = str(int(grid[i][co_j]) + 1)
                            max_v = max(max_v, int(grid[i][co_j]))
                            co_j += 1 
        
        return max_v








```