* 显然是一道bfs题目。关键是要**记录时间**，即如何在上一分钟腐烂的橘子和这一分钟腐烂的橘子之间划清界限。
* 方法1：可以按照官方题解，用`队列`这一数据结构。此时，我们记录时间的方法是把(i, j, minute)一起入队。
* 方法2：我用的数据结构是`数组`，一个while循环代表1min流逝。`rotten`表示这一分钟刚腐烂的橘子的坐标，`fresh`则为这一分钟新鲜的橘子。每一分钟刷新一下这两个数组即可。
    * step1：初始化`fresh`和`rotten`
    * step2：For every minute，如果`rotten`的四周有新鲜的橘子（即`in fresh`），那么把它加入`new_rotten`中。这一分钟结束时，新的`rotten`是`new_rotten`，新的`fresh`是原来的`fresh`减去`new_rotten`。循环中止条件：`new_rotten`为空。
    * 如果`fresh`为空，说明没新鲜橘子了，返回-1，否则返回`minute`。
* 时间复杂度：O（mn）；空间复杂度：O(mn)，新建数组。

```python []
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        rotten, fresh = [], []
        minute = 0
        m, n = len(grid), len(grid[0])

        # step1: find rotten orange and fresh orange
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh.append([i, j])
                elif grid[i][j] == 2:
                    rotten.append([i, j])

        # step2: for every minute, update #rotten until no update is made
        while True:
            new_rotten = []
            for pos in rotten:
                for d in direction:
                    temp = [pos[0]+d[0], pos[1]+d[1]]
                    if temp in fresh:
                        new_rotten.append(temp)
            if len(new_rotten) == 0:
                break
            new_fresh = []
            for pos in fresh:
                if pos not in new_rotten:
                    new_fresh.append(pos)
            rotten, fresh = new_rotten, new_fresh
            minute += 1

        return minute if len(fresh) == 0 else -1
```