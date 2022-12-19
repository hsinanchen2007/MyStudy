### 解题思路


### 代码

```python
#广度优先搜索方法 BFS
class Solution(object):
    def orangesRotting(self, grid):
        r,c = len(grid),len(grid[0])
        #找到坏橘子的坐标
        pos = [[x,y] for x in range(r) for y in range(c) if grid[x][y] == 2]
        #初始化访问情况，均未被访问
        visit_pos = [[False]*c for _ in range(r)]
        #感染方向矢量
        dir = [[-1,0],[1,0],[0,1],[0,-1]]
        #初始化时间
        count_minu = 0
        #开始感染新橘子
        while True:
            #初始化一个空间，用于存储本轮被传染的橘子
            bad_orange = []
            #pos不为空，则进行循环
            while pos:
                #坏橘子出列
                x,y = pos.pop()
                #判断坏橘子上下左右是否有待感染的新橘子
                for d in dir:
                    new_x,new_y = x + d[0],y + d[1]
                    #判断是否访问过，以及是否是新橘子
                    if -1 < new_x < r and -1 < new_y < c and not visit_pos[new_x][new_y] and grid[new_x][new_y] == 1:
                        #表示已访问
                        visit_pos[new_x][new_y] = True
                        #好橘子变成坏橘子
                        grid[new_x][new_y] = 2
                        #将新变坏的橘子添加到bad_orange
                        bad_orange.append([new_x,new_y])
            #如果bad_orange为空，说明没有好好橘子可以感染
            if not bad_orange:break
            #如果bad_orange不为空，而此时pos已经遍历完成，则把新一轮坏橘子放到pos,以便下一轮感染
            pos = bad_orange
            #时间加一分
            count_minu += 1
        #最后判断是否还有好橘子，有，返回-1，没有返回count_minu
        return -1 if[1 for i in range(c) for j in range(r) if grid[j][i] == 1] else count_minu
```