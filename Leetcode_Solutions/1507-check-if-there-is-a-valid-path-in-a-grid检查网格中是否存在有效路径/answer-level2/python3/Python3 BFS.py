### 解题思路
趁着人少，截个图：
![image.png](https://pic.leetcode-cn.com/874f9307e0c08111e62000291c14d5b5ac88626e45c1b96c14ea5326329a1e45-image.png)

关键在于重建图
如[1,1,2]
将被重建为：
[
 [0,0,0, 0,0,0, 0,1,0],
 [1,1,1, 1,1,1, 0,1,0],
 [0,0,0, 0,0,0, 0,1,0]
]
然后从新图的1,1出发，深度遍历，看能否遍历到右下角3*3矩阵的中心

### 代码

```python3
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        new_grid_1=[-1]*len(grid[0])*3
        new_grid=[new_grid_1.copy() for i in range(len(grid)*3)]
        print(len(new_grid))
        print(len(new_grid[0]))
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=0
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=1
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=1
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=0
                    new_grid[i*3+2][j*3+2]=0
                if grid[i][j]==2:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=1
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=0
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=0
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=1
                    new_grid[i*3+2][j*3+2]=0
                if grid[i][j]==3:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=0
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=1
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=0
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=1
                    new_grid[i*3+2][j*3+2]=0
                if grid[i][j]==4:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=0
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=0
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=1
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=1
                    new_grid[i*3+2][j*3+2]=0
                if grid[i][j]==5:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=1
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=1
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=0
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=0
                    new_grid[i*3+2][j*3+2]=0
                if grid[i][j]==6:
                    new_grid[i*3+0][j*3+0]=0
                    new_grid[i*3+0][j*3+1]=1
                    new_grid[i*3+0][j*3+2]=0
                    new_grid[i*3+1][j*3+0]=0
                    new_grid[i*3+1][j*3+1]=1
                    new_grid[i*3+1][j*3+2]=1
                    new_grid[i*3+2][j*3+0]=0
                    new_grid[i*3+2][j*3+1]=0
                    new_grid[i*3+2][j*3+2]=0
        stack=[(1,1)]
        while len(stack)>0:
            x,y=stack.pop()
            if x==(len(grid)-1)*3+1 and y==(len(grid[0])-1)*3+1:
                return True
            new_grid[x][y]=-1
            if x>0 and new_grid[x-1][y]==1:
                stack.append((x-1,y))
            if y>0 and new_grid[x][y-1]==1:
                stack.append((x,y-1))
            if x<len(new_grid)-1 and new_grid[x+1][y]==1:
                stack.append((x+1,y))
            if y<len(new_grid[0])-1 and new_grid[x][y+1]==1:
                stack.append((x,y+1))
        return False
```