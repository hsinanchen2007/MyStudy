### 解题思路
和螺旋矩阵思路类似
主要注意点为：**方向的改变操作**

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        list0 = [j for j in range(1,n**2 + 1)]                          # 生成长列表
        x = y = 0
        dx = [0,1,0,-1]                                                 # 方向坐标
        dy = [1,0,-1,0]
        di = 0
        visited = set()                                                 # 初始化集合，用于记录已走过坐标
        list1 = [[None for k in range(n)] for k in range(n)]            # 生成空矩阵
        for i in range(n**2):
            list1[x][y] = list0[i]                                      
            visited.add((x,y))
            nx,ny = x + dx[di],y+dy[di]                                 # 记录下一步操作
            if 0<=nx<n and 0<=ny<n and (nx,ny) not in visited:          # 判断是否越界，未曾走过的路
                x,y = nx,ny
            else:
                di = (di+1)%4
                x,y= x+dx[di],y+dy[di]
        return list1

```
少侠留步，随手点赞，明天脱单！