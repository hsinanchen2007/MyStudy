### 解题思路
设置一个方向，一旦触底就旋转方向

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        direction=[(0,1),(1,0),(0,-1),(-1,0)]
        matrix=[[0]*n for _ in range(n)]
        row,col=0,0
        d=0
        for i in range(n*n):
            dic=direction[d%4]

            matrix[row][col]=i+1
            newX,newY=row+dic[0],col+dic[1]
            
            if 0<=newX<n and 0<=newY<n and matrix[newX][newY]==0:
                row,col=newX,newY
            else:
                d+=1
                dic=direction[d%4]
                row,col=row+dic[0],col+dic[1]
        return matrix
                

            

            




```