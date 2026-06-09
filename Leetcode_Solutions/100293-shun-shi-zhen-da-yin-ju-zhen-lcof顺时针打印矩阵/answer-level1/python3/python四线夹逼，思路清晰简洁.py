### 解题思路
用四个变量框定每次打印的界限，相当于每次删掉一行或一列缩小范围

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m=len(matrix)
        if m==0:
            return []
        n=len(matrix[0])
        left=0
        right=n-1
        up=0
        bottom=m-1
        res=[]
        while len(res)<m*n:
            for j in range(left,right+1):
                res.append(matrix[up][j])
            up+=1
            for i in range(up,bottom+1):
                res.append(matrix[i][right])
            right-=1
            if up<=bottom: # 防止只有一行时的重复打印
                for j in range(right,left-1,-1):
                    res.append(matrix[bottom][j])
                bottom-=1
            if left<=right: # 防止只有一列时的重复打印
                for i in range(bottom,up-1,-1):
                    res.append(matrix[i][left])
                left+=1
        return res

```