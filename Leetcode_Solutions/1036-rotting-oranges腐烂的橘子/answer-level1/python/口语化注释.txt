### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        q = []
        x, y = len(grid), len(grid[0])
        for i in range(x):
            for j in range(y):
                if grid[i][j] == 2:
                    q.append((i, j))
        # q 有所有腐烂橘子坐标
        # bfs 
        t = 0
        while len(q):
            # 开始一层层腐烂
            cw = True
            for f in range(len(q)):
                i, j = q.pop(0)
                for d in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    n_i, n_j = i+d[0], j+d[1]
                    if 0<= n_i < x and 0<= n_j < y and grid[n_i][n_j] == 1:
                        grid[n_i][n_j] = 2  # 变烂啦
                        q.append((n_i, n_j))
                        if cw:
                            t += 1
                            cw = False


        # 全部橘子烂完，看看还有没有新鲜的
        for i in range(x):
            for j in range(y):
                if grid[i][j] == 1:
                    # 竟然还有新鲜的橘子
                    return -1
        
        # 没有新鲜橘子啦
        return t
```