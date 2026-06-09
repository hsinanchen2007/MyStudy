### 解题思路
此处撰写解题思路
主要注意的点：
1. 搜索的目的是找到还能继续搜索的点
2. 注意好标记访问过的点（没访问过的先标记成访问过的，然后才检查它是否还可以继续搜索）
3. 不然很容易造成重复进入访问过的点
### 代码

```python
class Solution(object):
    def __init__(self):
        self.rows = 0
        self.cols = 0
        self.visited = [[]]
        self.directions = [[0,1],[0,-1],[1,0],[-1,0]]

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        
        self.rows = len(grid)
        self.cols = len(grid[0])
        
        
        self.visited = [[0 for _ in range(self.cols)] for _ in range(self.rows)]
        print(self.visited)
        count = 0
        
        for x in range(self.rows):
            for y in range(self.cols):
                if grid[x][y] == "1" and self.visited[x][y]!= 1:
                    self.visited[x][y] = 1
                    count +=1
                    self._BFS(grid,x,y)
                    # print("(x,y) = {}, count = {}, visited = {}".format((x,y),count, self.visited))
                    # break
        
        return count
    
    def _BFS(self, grid, x, y):
        queue = [(x,y)]
        
        while queue:
            # print("queue = {}".format(queue))
            node = queue.pop(0)
            for d in self.directions:
                new_x = node[0]+d[0]
                new_y = node[1]+d[1]
                                
                
                if new_x>=0 and new_x<=self.rows-1 and new_y >=0 and new_y<=self.cols-1:
                    '''在地图上'''    
                    # print((new_x,new_y))
                    if self.visited[new_x][new_y]!= 1:
                        '''没来过'''
                        self.visited[new_x][new_y] =1
                        
                        if grid[new_x][new_y] == "1" :
                            '''开可以继续找'''
                            queue.append((new_x,new_y))
```