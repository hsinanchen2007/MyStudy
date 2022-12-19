### 解题思路
此处撰写解题思路
仔细观察，新的第i行，是原来的第i列的倒序。
### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        x=[]
        for i in range(n):
            y=[]
            for j in range(n):
                y.append(matrix[n-1-j][i])
            x.append(y)
        matrix[::]=x[::]
```