### 解题思路
执行时间很长，只是分享一下思路
不停的旋转矩阵，每次输出第一行，直到矩阵为空

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def T(matrix):
            rl=len(matrix)
            cl=len(matrix[0])
            newmartix=[[0 for i in range(rl)] for j in range(cl)]
            
            for i in range(cl):
                for j in range(rl):
                    newmartix[i][j]=matrix[j][cl-1-i]
            return newmartix

        re=[]
        while(matrix):
            re=re+matrix.pop(0)
            if matrix:
                matrix=T(matrix)
        return re

```