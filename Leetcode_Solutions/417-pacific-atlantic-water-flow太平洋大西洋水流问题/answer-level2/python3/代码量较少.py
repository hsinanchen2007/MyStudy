
![图片.png](https://pic.leetcode-cn.com/69a2f81e47ecefde2f0203dd9bac9e8e28b42eb22f5cb23b63d24f3885a41629-%E5%9B%BE%E7%89%87.png)
```
class Solution:
    def __init__(self):
        self.res = []
        self.buffer1 = []
        self.buffer2 = []
        self.directions = [(0,1),(1,0),(-1,0),(0,-1)]

    def find(self,matrix,bufferr,x,y,m,n):

        bufferr[x][y] = 1
        for i, j in self.directions:
            i, j = x+i, y+j
            if i < 0 or i > m-1 or j < 0 or j > n-1 or bufferr[i][j] or matrix[x][y] > matrix[i][j]:
                continue
            self.find(matrix,bufferr,i,j,m,n)

    def pacificAtlantic(self, matrix):
        if not matrix:return matrix
        m = len(matrix)
        n = len(matrix[0])
        self.buffer1 = [[0]*n for i in range(m)]
        self.buffer2 = [[0]*n for i in range(m)]
        for i in range(n):
            self.find(matrix,self.buffer1,0,i,m,n)
            self.find(matrix,self.buffer2,m-1,i,m,n)
        for i in range(m):
            self.find(matrix,self.buffer1,i,0,m,n)
            self.find(matrix,self.buffer2,i,n-1,m,n)

        for i in range(m):
            for j in range(n):
                if self.buffer1[i][j] + self.buffer2[i][j] == 2:
                    self.res.append((i,j))
        return self.res 

```
