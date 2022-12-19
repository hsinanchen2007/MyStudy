### 解题思路
如题
先把矩阵转置，然后再把每一行逆序
### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        if not n: return 
        for i in range(n):
            for j in range(i):
                tmp=matrix[i][j]
                matrix[i][j]=matrix[j][i]
                matrix[j][i]=tmp
        for i in range(n):
            matrix[i]=matrix[i][::-1]
```