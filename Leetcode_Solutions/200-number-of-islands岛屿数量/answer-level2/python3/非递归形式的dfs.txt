
本道题的核心思想就是dfs,利用两个栈来实现非递归的版本。
```
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        grid_t = [[0]*(n+2) for _ in range(m+2)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                grid_t[i][j] = int(grid[i-1][j-1])
        count = 0
        stack = []
        # print(grid_t)
        for i in range(1, m+1):
            for j in range(1, n+1):
                if grid_t[i][j] == 1:
                    if grid_t[i-1][j] == 0 and grid_t[i+1][j]==0 and grid_t[i][j-1] == 0 and grid_t[i][j+1]==0:
                        count += 1
                        grid_t[i][j] = 0
                    else:
                        stack.append((i, j))
        if stack:
            stack_tmp = []
            while stack:
                stack_tmp.append(stack[0])
                count += 1
                while stack_tmp:
                    p = stack_tmp.pop(0)
                    while grid_t[p[0]][p[1]] == 1:
                        # print(p)
                        if p in stack_tmp:
                            stack_tmp.remove(p)
                        stack.remove(p)
                        if grid_t[p[0]+1][p[1]] == 1:
                            stack_tmp.append((p[0]+1, p[1]))
                        if grid_t[p[0]][p[1]-1] == 1:
                            stack_tmp.append((p[0], p[1]-1))
                        if grid_t[p[0]-1][p[1]] == 1:
                            stack_tmp.append((p[0]-1, p[1]))
                        grid_t[p[0]][p[1]] = 0
                        p = (p[0], p[1]+1)
        return count
```
