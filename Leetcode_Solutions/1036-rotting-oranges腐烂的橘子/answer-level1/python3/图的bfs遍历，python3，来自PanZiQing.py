```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:     # 图的bfs遍历 | 迭代 | 队列
        m, n = len(grid), len(grid[0])
        visited = [[False]*n for i in range(m)]     # 记住
        queue = [[y,x] for y in range(m) for x in range(n) if grid[y][x] == 2]     # 记住
        direction = [[-1,0], [1,0], [0,-1], [0,1]]
        minute = 0

        while True:   # 这里不是while queue，是因为我要统计时间，和传统写法有点不一样
            queue_next = []
            while queue:
                y,x = queue.pop(0)      # 其实这里用stack还是queue都行
                for direct in direction:
                    y_new, x_new = y + direct[0], x+ direct[1]
                    # 判断这样的(y_new, x_new) 要不要append进去
                    if -1<y_new and y_new < m and x_new > -1 and x_new <n and not visited[y_new][x_new] and grid[y_new][x_new]==1:
                        queue_next.append([y_new,x_new])
                        visited[y_new][x_new] = True
                        grid[y_new][x_new] = 2
            if len(queue_next) == 0:
                break
            else:
                queue = queue_next      # 注意queue和queue_next的关系
                minute +=1
        # 经过传染，审查，隔离的循环后，如果还有好橘子幸存，返回-1宣布胜利，否则返回橘子们的存活时间
        return -1 if ['survive' for y in range(m) for x in range(n) if grid[y][x]==1] else minute   # 最后这个survive是自定义的，是哪个都行
```
