while循一次，表示时间过了一个单位，time+1，所有现存的烂橘子循环一轮。
但是在while循环里，每一个烂橘子污染的别的橘子也要入队。因此用for循环，range（len（queue））来限制本次的循环次数————————所有上一轮所存在的烂橘子进行处理，新入队的烂橘子不进行运算，等待下一轮。

牛牛牛

```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        M = len(grid)
        N = len(grid[0])
        queue = []
        
        count = 0 # count 表示新鲜橘子的数量
        for r in range(M):
            for c in range(N):
                if grid[r][c] == 1:
                    count += 1
                elif grid[r][c] == 2:
                    queue.append((r, c))
                    
        round = 0 # round 表示腐烂的轮数，或者分钟数
        while count > 0 and len(queue) > 0:
            round += 1 
            n = len(queue)
            for i in range(n):
                r, c = queue.pop(0)
                if r-1 >= 0 and grid[r-1][c] == 1:
                    grid[r-1][c] = 2
                    count -= 1
                    queue.append((r-1, c))
                if r+1 < M and grid[r+1][c] == 1:
                    grid[r+1][c] = 2
                    count -= 1
                    queue.append((r+1, c))
                if c-1 >= 0 and grid[r][c-1] == 1:
                    grid[r][c-1] = 2
                    count -= 1
                    queue.append((r, c-1))
                if c+1 < N and grid[r][c+1] == 1:
                    grid[r][c+1] = 2
                    count -= 1
                    queue.append((r, c+1))
        
        if count > 0:
            return -1
        else:
            return round
```
