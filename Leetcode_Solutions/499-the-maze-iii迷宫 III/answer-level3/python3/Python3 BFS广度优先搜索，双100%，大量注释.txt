```
class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
                                                    
        directions = [(-1,0,'u'),(0,1,'r'),(0,-1,'l'),(1,0,'d')]    
                                                    # 定义上下左右四个方向和对应字符
        m = len(maze)                               # 获取矩阵大小
        n = len(maze[0])
        queue = [(ball[0],ball[1])]                 # 构造队列，并将起始位置包含其中
                                                    # distance 保存从起点到每个点的距离
                                                    # string 保存每个点对应的字符串
        distance = [[float('inf')]*n for _ in range(m)]
        string = [["impossible"]*n for _ in range(m)]
        distance[ball[0]][ball[1]] = 0              # 对起点的distance和string进行初始化
        string[ball[0]][ball[1]] = ""

        while queue:
            i,j = queue.pop(0)                      # 弹出坐标值i,j
            
            for dx,dy,letter in directions:         # 对四个方向进行遍历，letter保存了操作对应的字符
                x,y,step,word =i+dx,j+dy,distance[i][j],string[i][j]
                while 0<=x<m and 0<=y<n and maze[x][y] == 0 and (x-dx!=hole[0] or y-dy!=hole[1]):                                      
                                                    # 当x,y坐标合法，并且对应值为0
                                                    # 且没有越过hole时
                    x = x+dx                        # 继续前进，模拟小球的滚动过程
                    y = y+dy                        
                    step += 1                       # 记录步数

                x = x - dx
                y = y - dy

                if distance[x][y] > step or (distance[x][y]==step and word+letter<string[x][y]):           
                                                    # 如果起点到该点的距离比当前距离大
                                                    # 或者相等，但是字符串的字典序大
                                                    # 更新该距离和字符串，并将坐标加入队列
                    distance[x][y] = step
                    string[x][y] = word+letter
                    #print(x,y,string[x][y])   
                    if x!=hole[0] or y!=hole[1]:    # 当坐标不是hole坐标时
                        queue.append((x,y))         # 将其添加到队列中
                                           
        return string[hole[0]][hole[1]]
```


![微信截图_20200114094332.png](https://pic.leetcode-cn.com/9ec702e9a4328f1b2eebe758f7b8965d7281820e2e53fdeeee98f8baae4e09a0-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200114094332.png)
