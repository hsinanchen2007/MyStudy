```python []
from copy import copy

class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        # 记录所有可能性
        result = []
        # 记录路线行走的轨迹
        queue = []
        # visit[x][y]表示grid[x][y]是否访问过
        visit = [[0] * len(grid[0]) for _ in range(len(grid))]
        # 记录起点
        start = []
        # 记录终点
        end = []
        # count[0]表示grid[x]=0的个数 count[1]表示以及访问过的点的个数
        count = [0, 0]

        # 找到起点，终点，一共需要通过的点的个数
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    start = [i, j]
                if grid[i][j] == 2:
                    end = [i, j]
                if grid[i][j] == 0:
                    count[0] += 1

        def dfs(x, y):
            """
            回溯法
            """
            # 如果到达终点
            if x == end[0] and y == end[1]:
                # 只有遍历完所有能走的路再到终点，再添加至result
                if count[0] == count[1]-1:
                    result.append([copy(i) for i in queue])
                return

            # 从上面走 [x-1,y]
            # 判断是否能走，能走再走，然后进行下一步dfs
            if x - 1 >= 0 and grid[x - 1][y] != -1 and visit[x - 1][y] == 0:
                visit[x - 1][y] = 5
                count[1] += 1
                queue.append([x-1, y])
                dfs(x - 1, y)
                # 回退
                visit[x - 1][y] = 0
                count[1] -= 1
                del queue[-1]

            # 从右边走[x,y+1]
            # 判断是否能走，能走再走，然后进行下一步dfs
            if y + 1 < len(grid[0]) and grid[x][y + 1] != -1 and visit[x][y + 1] == 0:
                visit[x][y + 1] = 5
                count[1] += 1
                queue.append([x, y+1])
                dfs(x, y + 1)
                # 回退
                visit[x][y + 1] = 0
                count[1] -= 1
                del queue[-1]

            # 从下边走[x+1,y]
            # 判断是否能走，能走再走，然后进行下一步dfs
            if x + 1 < len(grid) and grid[x + 1][y] != -1 and visit[x + 1][y] == 0:
                visit[x + 1][y] = 5
                count[1] += 1
                queue.append([x + 1, y])
                dfs(x + 1, y)
                # 回退
                visit[x + 1][y] = 0
                count[1] -= 1
                del queue[-1]

            # 从左边走[i,y-1]
            # 判断是否能走，能走再走，然后进行下一步dfs
            if y - 1 >= 0 and grid[x][y - 1] != -1 and visit[x][y - 1] == 0:
                visit[x][y - 1] = 5
                count[1] += 1
                queue.append([x, y-1])
                dfs(x, y - 1)
                # 回退
                visit[x][y - 1] = 0
                count[1] -= 1
                del queue[-1]

        visit[start[0]][start[1]] = 5
        queue.append([start[0], start[1]])
        dfs(start[0], start[1])
        return len(result)
```

```
