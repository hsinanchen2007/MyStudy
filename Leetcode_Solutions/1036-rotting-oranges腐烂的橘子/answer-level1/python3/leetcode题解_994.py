### 解题思路
mark自己的问题：问题能理解，也能画出来，可是写不出来（我可太菜了T^T），bfs也要灵活运用
又分析了一波官方题解，理解了这个**多源**广度遍历。
1.橘子是一起坏的，多个传染源
2.会存在被保护得*好好的*的橘子
3.广度遍历借助队列

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 多源广度遍历
        R,C = len(grid), len(grid[0])

        # queue - all starting cells with rotting oranges
        queue = collections.deque() # collections中deque可以实现高效队列，可双向访问
        for r , row in enumerate(grid): # 
            for c,val in enumerate(row):
                if val == 2:
                    queue.append((r,c,0))
        
        def neighbors(r, c):
            for nr, nc in ((r-1,c),(r,c-1),(r+1,c),(r,c+1)):# 列举给定位置的4个正方向
                if 0<= nr < R and 0 <= nc < C:
                    yield nr,nc
        
        d = 0
        while queue:
            r,c,d = queue.popleft()
            for nr,nc in neighbors(r, c):
                if grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    queue.append((nr,nc,d+1))
        if any(1 in row for row in grid):
            return -1
        return d
```