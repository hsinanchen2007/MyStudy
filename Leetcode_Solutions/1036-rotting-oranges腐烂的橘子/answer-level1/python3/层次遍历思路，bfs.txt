### 解题思路
一个队列q1储存当前腐烂的橘子，增加一个队列q2作为中转存储我们接下来pop出的腐烂橘子能感染的周围橘子。等q1 pop完了再把中转的队列q2的元素放到q1,清空q2。这个思路就和二叉树的层次遍历是一样的了。

### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        bfs = []
        mid = []
        n = len(grid)
        m = len(grid[0])
        count = 0 #good oranges
        round = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    bfs.append((i, j))
                elif grid[i][j] == 1:
                    count += 1

        while bfs and count > 0:
            while bfs:
                a, b = bfs.pop()
                if a-1 >= 0 and grid[a-1][b] == 1:
                    grid[a-1][b] = 2
                    mid.append((a-1, b))
                    count -= 1
                if a+1 < n and grid[a+1][b] == 1:
                    grid[a+1][b] = 2
                    mid.append((a+1, b))
                    count -= 1
                if b-1 >= 0 and grid[a][b-1] == 1:
                    grid[a][b-1] = 2
                    mid.append((a, b-1))
                    count -= 1
                if b+1 < m and grid[a][b+1] == 1:
                    grid[a][b+1] = 2
                    mid.append((a, b+1))
                    count -= 1
            round += 1
            bfs, mid = mid, []
        
        if count > 0:
            return -1
        return round


                

```