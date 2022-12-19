### 解题思路
BFS

### 代码

```python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        #找到所有值为1的位置坐标
        pos = [(x,y) for x in range(len(grid)) for y in range(len(grid[0])) if grid[x][y] == 1]
        #方向
        dir = [(0,1),(-1,0),(1,0),(0,-1)]
        #是否被访问的标记变量 未被访问过 visit = 0，已被访问过，visit = 1
        visit = [[0]*len(grid[0]) for _ in range(len(grid))]
        #初始化最大面积为0
        max_area = 0
        cur_area = 0
        #开始遍历
        while pos:
            x,y = pos.pop(0)
            cur_area += 1
            #用于临时缓存位置为1的地方
            stack = [(x,y)]
            while stack:
                x,y = stack.pop(0)
                #中心位置首先标记
                visit[x][y] = 1
                for d in dir:
                    #查看该方向位置坐标处是否为1
                    new_x,new_y = x + d[0],y + d[1]
                    if 0 <= new_x < len(grid) and 0 <= new_y < len(grid[0]) and not visit[new_x][new_y] and grid[new_x][new_y] == 1:
                        #新位置标记，下次不再访问
                        visit[new_x][new_y] = 1
                        cur_area += 1
                        #将新访问到的值为1的坐标加入临时站，查找该坐标周围是否存在1
                        stack.append((new_x,new_y))
            #更新最大面积
            max_area = max(max_area,cur_area)
            #恢复初始值，进行新位置的查找
            cur_area = 0
        return max_area

```