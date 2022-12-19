```python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        #array[0].length array[0].length  第二维的长度（当然这个array数组中要有元素，不然取array[0]就会报错的
        if not grid or not grid[0]:
            return 0
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.bfs(grid, i, j)
                    islands += 1
            
        return islands
    
    def bfs(self, grid, x, y):
        queue = collections.deque([(x, y)])
        grid[x][y] = '0'   #1改为0是避免重复添加
        while queue:
            x, y = queue.popleft()
            for delta_x, delta_y in [(1,0), (0,-1), (-1,0), (0,1)]:
                next_x = x + delta_x
                next_y = y + delta_y
                if not self.is_valid(grid, next_x, next_y):
                    continue
                queue.append((next_x, next_y))
                grid[next_x][next_y] = '0'
                                    
    def is_valid(self, grid, x, y):     #判断是不是岛
        n, m = len(grid), len(grid[0])
        return 0 <= x < n and 0 <= y < m and grid[x][y] == '1'  #大于0是防止数组越界 