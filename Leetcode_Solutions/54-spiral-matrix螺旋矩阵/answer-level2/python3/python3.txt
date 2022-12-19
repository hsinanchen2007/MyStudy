### 解题思路
设定一个方向矩阵，一直绕着转就行

### 代码

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return 
        direction=[(0,1),(1,0),(0,-1),(-1,0)] #左，下，右，上
        row,col=len(matrix),len(matrix[0])
        visited=[[False] * col for _ in range(row)]
        step=0
        x,y=0,0
        res=[]
        for i in range(row * col):
            res.append(matrix[x][y])
            visited[x][y]=True
            newX,newY=x+direction[step][0],y+direction[step][1]
            if 0<=newX<row and 0<=newY<col and not visited[newX][newY] :
                x,y=newX,newY  
            else:
                step=(step+1)%4
                x,y=x+direction[step][0],y+direction[step][1]
        return res
                
```
