### 解题思路
BFS遍历

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #存储网格行列数，设置初始时间为零
        row, col, time = len(grid), len(grid[0]), 0
        #设置方位列表，分别代表上,下,左,右
        direction = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        #初始一个队列，将腐烂的橘子位置和时间，入队
        RotQueue = []
        #遍历整个网格
        for i in range(row):
            for j in range(col):
                if(grid[i][j]==2):#所在网格为腐烂橘子
                    RotQueue.append((i, j, time))
        # if(not RotQueue):#若初始时间网格中没有腐烂橘子，直接返回不可能
        #     return -1
        
        #BFS
        while(RotQueue):
            r, c, time = RotQueue.pop(0)#弹出队列中第一个腐烂橘子的位置和腐烂时间
            for dr, dc in direction:#上下左右进行遍历
                if(0<=r+dr<row and 0<=c+dc<col and grid[r+dr][c+dc] == 1):
                    grid[r+dr][c+dc] = 2
                    RotQueue.append((r+dr, c+dc, time+1))
        #如果BFS后，网格中还有新鲜的橘子，说明不可能
        for r in grid:
            if 1 in r:
                return -1
        return time

```