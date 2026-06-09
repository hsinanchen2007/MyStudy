### 解题思路
用递归法一圈一圈打印
关键在于递归出口的判断，m<=2或n<=2都可以直接作为递归出口

### 代码

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        self.res=[]
        m=len(matrix)
        if m==0:
            return []#很烦这些判断
        n=len(matrix[0])
        if n==0:
            return []

        def getNum(mat,m,n):          
            self.res+=mat[0]#先添加第一行
            
            #递归出口
            if m==1:
                return
            elif m==2:
                self.res+=mat[m-1][::-1]
                return
            if n==1:
                for j in range(1,m):
                    self.res+=[mat[j][0]]
                return
            elif n==2:
                for j in range(1,m):
                    self.res+=[mat[j][1]]
                for j in range(m-1,0,-1):
                    self.res+=[mat[j][0]]
                return
            
            #添加一圈
            for j in range(1,m-1):
                    self.res+=[mat[j][n-1]]
            self.res+=mat[m-1][::-1]
            for j in range(m-2,0,-1):
                    self.res+=[mat[j][0]]
            getNum([x[1:n-1] for x in mat[1:m-1]],m-2,n-2)
    
        getNum(matrix,m,n)
        return self.res
```