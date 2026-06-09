### 解题思路
1.  所有腐烂

### 代码
1. 将所有腐烂橘子入队，腐蚀时间初始化为0
2. 遍历所有腐烂橘子四邻接方位，腐蚀所有四邻接方位的新鲜橘子（每次腐蚀时间1分钟，腐蚀需要的总时间==腐蚀总次数）
3. 腐蚀队列遍历完毕，检查grid中是否还有新鲜橘子，若有，则不可能，返回-1，否则，返回腐蚀总次数也就是腐蚀总时间
```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rot_q = []
        r, c = len(grid), len(grid[0])
        
        for i in range(r):
            for j in range(c):                               
                if grid[i][j] == 2:
                    rot_q.append((i,j, 0))
        res = 0
        adjoin_4 = [(0, 1), (0, -1), (-1, 0),(1, 0)]
        for x, y, res in rot_q:
            for xj, yj in adjoin_4:
                xj = x + xj
                yj = y + yj
                if 0 <= xj < r and 0 <= yj <c and grid[xj][yj] == 1:
                    grid[xj][yj] = 2
                    rot_q.append((xj, yj , res+1))
        if any(1 in row for row in grid):
            return -1
        return res

        return res
```