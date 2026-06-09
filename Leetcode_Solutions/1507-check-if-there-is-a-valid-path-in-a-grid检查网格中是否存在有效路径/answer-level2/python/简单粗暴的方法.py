### 解题思路
![截屏2020-03-23下午11.17.44.png](https://pic.leetcode-cn.com/40bcf54cf92180e459b48b017e5eac5d2a60ceb743cc05d827ff0a98f0d4f8d8-%E6%88%AA%E5%B1%8F2020-03-23%E4%B8%8B%E5%8D%8811.17.44.png)
每个格子都有两种进入方向，而一种进入方法对应唯一的离开格子方向，所以就可以结合当前格子内的值和进入方向得到对应的下一个格子的坐标，在判断以当前格子的离开方向能否进入下一个格子，如不能，则返回False，如可以，则以下一格子和和对应的进入方向开始下一次迭代，直到到达终点。
### 代码

```python3
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        r,c=len(grid),len(grid[0])
        t=0
        def func(t):
            i=j=0
            while True:
                if i==r-1 and j==c-1:return True
                if grid[i][j]==1 and t==3:
                    if j==0 or grid[i][j-1]==2 or grid[i][j-1]==3 or grid[i][j-1]==5:return False
                    j-=1
                elif grid[i][j]==1 and t==4:
                    if j==c-1 or grid[i][j+1]==2 or grid[i][j+1]==4 or grid[i][j+1]==6:return False
                    j+=1
                elif grid[i][j]==2 and t==1:
                    if i==0 or grid[i-1][j]==1 or grid[i-1][j]==5 or grid[i-1][j]==6:return False     
                    i-=1      
                elif grid[i][j]==2 and t==2:
                    if i==r-1 or grid[i+1][j]==1 or grid[i+1][j]==3 or grid[i+1][j]==4:return False     
                    i+=1
                elif grid[i][j]==3 and t==1:
                    if j==0 or grid[i][j-1]==2 or grid[i][j-1]==3 or grid[i][j-1]==5:return False
                    t=3
                    j-=1  
                elif grid[i][j]==3 and t==4:
                    if i==r-1 or grid[i+1][j]==1 or grid[i+1][j]==3 or grid[i+1][j]==4:return False
                    t=2
                    i+=1
                elif grid[i][j]==4 and t==1:
                    if j==c-1 or grid[i][j+1]==2 or grid[i][j+1]==4 or grid[i][j+1]==6:return False     
                    t=4
                    j+=1
                elif grid[i][j]==4 and t==3:
                    if i==r-1 or grid[i+1][j]==1 or grid[i+1][j]==3 or grid[i+1][j]==4:return False
                    t=2
                    i+=1  
                elif grid[i][j]==5 and t==2:
                    if j==0 or grid[i][j-1]==2 or grid[i][j-1]==3 or grid[i][j-1]==5:return False
                    t=3
                    j-=1
                elif grid[i][j]==5 and t==4:
                    if i==0 or grid[i-1][j]==1 or grid[i-1][j]==5 or grid[i-1][j]==6:return False     
                    t=1
                    i-=1
                elif grid[i][j]==6 and t==2:
                    if j==c-1 or grid[i][j+1]==2 or grid[i][j+1]==4 or grid[i][j+1]==6:return False
                    t=4
                    j+=1  
                elif grid[i][j]==6 and t==3:
                    if i==0 or grid[i-1][j]==1 or grid[i-1][j]==5 or grid[i-1][j]==6:return False
                    t=1
                    i-=1
        if grid[0][0]==1:return func(4)
        elif grid[0][0]==2:return func(2)
        elif grid[0][0]==3:return func(4)
        elif grid[0][0]==4:
            return func(1) or func(3)
        elif grid[0][0]==5:return False
        else:return func(2)
```