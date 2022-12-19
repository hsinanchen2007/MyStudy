### 解题思路
不能写等于，用[:]代替

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        mylist=[([0]*n) for i  in range(n)]
        for i in range(n):
            k=n-i-1
            for j in range (n):
                mylist[j][k]=matrix[i][j]
        matrix[:] = mylist


```