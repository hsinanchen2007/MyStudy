### 解题思路
直接暴力，可以剪枝，在这里我没做

### 代码

```
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        self.res=0
        row,col=len(A),len(A[0])
        def comparison(x_move,y_move):
            tmp=0
            for i in range(row):
                for j in range(col):
                    newX,newY=x_move+i,y_move+j
                    if 0<=newX<row and 0<=newY<col:
                        if A[newX][newY]==1 and A[newX][newY]==B[i][j]:
                            tmp+=1
            self.res=max(self.res,tmp)
        for i in range(-row+1,row):
            for j in range(-col+1,col):
                comparison(i,j)
        return self.res
      
```