### 解题思路
遍历矩阵，在元素为0的位置打标记 （这里用的是 float('inf'）)
对标记元素所在列和所在行 中所有的非0元素进行打标记
###### 备注：对同行或列中的0不再打标记，防止未遍历到的地方不能进行行列打标操作。
最后把矩阵中的标记处更改为0
时间复杂度稍高
### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n,m = len(matrix),len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j]==0:
                    for x in range(n):
                        if matrix[x][j] != 0:
                            matrix[x][j] = float('inf')
                    for y in range(m):
                        if matrix[i][y] != 0:
                            matrix[i][y] = float('inf')
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == float('inf'):matrix[i][j]=0
        return matrix   
```