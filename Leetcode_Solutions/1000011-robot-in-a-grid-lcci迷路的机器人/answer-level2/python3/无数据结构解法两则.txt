### 解题思路
大二算法小白，刚学数据结构，看到题目最开始的想法是递归，写着写着想到了以前学计算机网络的时候有一种路由算法，具体操作见代码注释。

### 代码

```python3
# 递归算法
class Solution:
    def move(self, path, now, grid, r, c):                  # 传入递归变量path(保存正确路径)，现在的位置，整个地图，以及地图大小(重复传入避免重复计算)
        print(now)
        if now==[r-1, c-1]:                                     # 递归终止条件: 现在在终点
            path.insert(0, now)                                     # 把当前位置(终点)插入正确路径的首位(因为它是第一个完成的所以插在首位，后面的位置都插在他前面)
            return True, now
        else:                                                   # 递归: 若不在终点
            if now[1]<=c-2 and grid[now[0]][now[1]+1]==0:           # 若当前位置的右边可行进(注意与可完成的区别)，则
                next_op = [now[0], now[1]+1]                            # 下一步向右
                now_way = self.move(path, next_op, grid, r, c)          # 接受向右的结果
                if now_way[0]:                                              # 向右可到达(则当前位置可到达)
                    path.insert(0, now)                                     # 把当前位置插在历史记录的可到达路径的首位
                    return True, path
                elif now[0]<=r-2 and grid[now[0]+1][now[1]]==0:     # 若右方不可行进
                    next_op = [now[0]+1, now[1]]                        # 则尝试下方
                    now_way = self.move(path, next_op, grid, r, c)      # 接受向下的结果
                    if now_way[0]:                                          # 向下可到达(则当前位置可到达)
                        path.insert(0, now)                                 # 把当前位置插在历史记录的可到达路径的首位
                        return True, path
                    else:                                           # 若右方与下方均不可到达
                        return False,                                   # 则当前位置不可到达终点
                else:
                    return False, 
            elif now[0]<=r-2 and grid[now[0]+1][now[1]]==0:         # 若右方不可行进(如有障碍物或者到地图边缘)
                next_op = [now[0]+1, now[1]]                            # 下一步向下
                now_way = self.move(path, next_op, grid, r, c)
                if now_way[0]:
                    path.insert(0, now)
                    return True, path
                else:
                    return False, 
            else:                                                   # 若右方与下方均不可行进
                return False,                                           # 则当前位置不可到达

    def pathWithObstacles(self, obstacleGrid: List[List[int]]) -> List[List[int]]:
        r = len(obstacleGrid)
        c = len(obstacleGrid[0]) # 记录下地图的大小
        if r==1 and c==1:   # 如果是1x1直接返回结果
            if obstacleGrid[0][0]==0:
                return [[0, 0]]
            else:
                return []
        if obstacleGrid[0][0]==1 or obstacleGrid[r-1][c-1]==1: # 如果起点或者终点有障碍物则判否
            return []
        way = self.move([], [0, 0], obstacleGrid, r, c) # 递归运算，返回值是元组，way[0]表示是否存在路径，way[1]给出路径
        print(way)
        if way[0]:
            return way[1]
        else:
            return []
'''
    递归运算的重点是找准初始条件和递归条件。
    本题的终点在于：在判右不可到达和判右不可行进后要分别判断向下是否可行，不注意这点很容易出错。
    用时240ms，内存28.8mb
'''


```python3
# 路由算法
class Solution:
    def getRouteTable(self, obstacleGrid):                                              # 
        r = len(obstacleGrid)
        c = len(obstacleGrid[0])
        routeTable = [[[False, False, False] for _ in range(c+1)] for _ in range(r+1)]  # 路由表初始化: 比原始地图在左边和上边多一圈围墙，三个值分别为:当前位置是否可到达终点，右方是否能到达终点，下方是否能到达终点。路由表相当于原表旋转180°，然后在上面和左边加一层围墙，原来的向右向下走在路由表中分别是向左向上走
        for r_index, row in enumerate(obstacleGrid[::-1]):                                  # 遍历原表
            for c_index, col in enumerate(row[::-1]):
                if c_index==0 and r_index==0:                                               # 如果是起点
                    routeTable[r_index+1][c_index+1] = [True, True, True]                       # 则三者皆可到达
                    continue
                if col==1:                                                                  # 如果是障碍物
                    routeTable[r_index+1][c_index+1] = [False, False, False]                    # 则三者皆不可到达
                    continue                                                                # 如果判定是上述二者则皆不用下面的判定
                if routeTable[r_index+1][c_index][0] or routeTable[r_index][c_index+1][0]:  # 如果上方或左方的位置可抵达终点
                    routeTable[r_index+1][c_index+1][0] = True                                  # 则当前位置可抵达终点
                    if routeTable[r_index+1][c_index][0]:                                       # 设置当前位置路由(确定上方与左方可以抵达终点的方向)
                        routeTable[r_index+1][c_index+1][1] = True
                    else:
                        routeTable[r_index+1][c_index+1][1] = False
                    if routeTable[r_index][c_index+1][0]:
                        routeTable[r_index+1][c_index+1][2] = True
                    else:
                        routeTable[r_index+1][c_index+1][2] = False
                else:                                                                       # 否则不可抵达终点
                    routeTable[r_index+1][c_index+1] = [False, False, False]
        return routeTable                                                               # 返回路由表

    def getRoute(self, rt):                                     # 传入路由表
        r = len(rt)                                             # 路由表大小比原地图大小长和宽分别大1
        c = len(rt[0])
        if not rt[r-1][c-1][0]:                                 # 如果起点不可抵达终点
            return []                                               # 则不用遍历直接判否
        else:                                                   # 否则开始查看路由表
            ret = []                                                # 返回值
            now = [0, 0]                                            # 初始位置为起点
            while 1:                                                # 循环直到抵达终点
                ret.append(now.copy())                                  # 将当前位置保存进返回值中(注意python当中传递变量传的是变量的引用，所以不可直接传now，需要传now的拷贝)
                if now[0]==r-2 and now[1]==c-2:                         # 抵达终点
                    break                                                   # 跳出循环
                if rt[r-1-now[0]][c-1-now[1]][1]:                       # 向左可到
                    now[1] += 1                                             # 向左走
                    continue            
                else:                                                   # 否则则向上可到
                    now[0] += 1                                             # 向上走
            return ret

    def showT(self, t):
        for i in range(len(t)):
            for j in range(len(t[i])):
                print(t[i][j], end="\t")
            print()


    def pathWithObstacles(self, obstacleGrid: List[List[int]]) -> List[List[int]]:
        r = len(obstacleGrid)
        c = len(obstacleGrid[0])    # 保存地图常量
        if obstacleGrid[0][0]==1 or obstacleGrid[r-1][c-1]==1:      # 如果起点终点为障碍物直接判否
            return []
        if r==1 and c==1:                                           # 否则1x1必有结果
            return [[0, 0]]
        rt = self.getRouteTable(obstacleGrid)                       # 取得路由表
        self.showT(rt)
        return self.getRoute(rt)                                    # 根据路由表得到路径

'''
    路由表其实不是什么新鲜的东西，在一个多次更新的网络当中一台主机总能找到最近的到另一台主机的路由。
    耗时120ms，内存28.8mb

'''
```