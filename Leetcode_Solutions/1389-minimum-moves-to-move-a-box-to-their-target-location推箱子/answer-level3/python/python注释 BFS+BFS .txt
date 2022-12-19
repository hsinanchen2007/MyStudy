判断箱子能否到达目标位置。
箱子能够向某个方向移动的前提是，人可以到达该方向上箱子的后方。
例如，要将箱子向上推，人必须可以到达箱子的下方。
所以BFS搜索箱子能否到达目标位置，箱子向某方向移动的前提是，BFS搜索，人可以到达该方向箱子后方。

```
class Solution(object):
    def minPushBox(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.move = [[1,0],[-1,0],[0,1],[0,-1]]
        self.N,self.M =len(grid),len(grid[0])
   
     
        for i in range(self.N):
            for j in range(self.M):
                if grid[i][j] == 'B':
                    grid[i][j] = '.'
                    #清除盒子位置每次搜索时更新（因为盒子对人来说相当于是墙，不可直接穿过，需要更新）
                    bx,by = i,j
                if grid[i][j] == 'S':
                    grid[i][j] = '.'
                    #清除人起点位置，找到起点后，不再需要‘s'标记
                    sx,sy = i,j    
        #查找初始人和箱子的位置
        s = set(str([bx,by,sx,sy]))
        #状态记录
        t = [[bx,by,sx,sy,0]]   
        #搜索队列                  
        while t:
            bx,by,sx,sy,step = t.pop(0)
            #bx,by箱子的位置，sx,sy人的位置，step为步数
            if grid[bx][by]=='T':
            #箱子到达目标位置'T'，返回step步数
                return step   
            grid[bx][by] = 'B'
	        #更新图中箱子位置
            for dx,dy in self.move:
                if dx+bx>=0 and dx+bx<self.N and dy+by>=0 and dy+by<self.M and grid[dx+bx][dy+by] in ".T":
	            #箱子未移出边界，且箱子可移动
                    if -dx+bx>=0 and -dx+bx<self.N and -dy+by>=0 and -dy+by<self.M and grid[-dx+bx][-dy+by] in ".T":
                    #当前箱子后方无障碍
                        if self.bfs(sx,sy,-dx+bx,-dy+by,grid):
                        #BFS搜索人(sx,sy)可以到达箱子后方(-dx+bx,-dy+by),可以到达返回True
                            if str([dx+bx,dy+by,bx,by]) not in s:
                            #该状态未到达过
                                t.append([dx+bx,dy+by,bx,by,step+1])
                                s.add(str([dx+bx,dy+by,bx,by]))
                                #搜索并记录该状态
            grid[bx][by] = '.'
            #删除箱子，便于下次更新箱子位置
          
        return -1
    def bfs (self,sx,sy,ex,ey,road):
    #BFS搜索人是否能从sx,sy到达ex,ey
        
        t = [[sx,sy]]
        s = set(str([sx,sy]))
        #搜索队列t和状态记录集合s
        while t:
            x,y = t.pop(0)
            if [x,y] == [ex,ey]:
            #到达ex,ey返回True
                return True
            for dx,dy in self.move:
                #搜索(x+dx,y+dy)4个位置
                if dx+x>=0 and dx+x<self.N and dy+y>=0 and dy+y<self.M and road[dx+x][dy+y] in ".T":
                    if str([dx+x,dy+y]) not in s:
                        t.append([dx+x,dy+y])
                        s.add(str([dx+x,dy+y]))
            
        #搜索完毕未到达，返回False
        return False
                


```


