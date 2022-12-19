### 解题思路
先转置矩阵，然后翻转每一行。
![image.png](https://pic.leetcode-cn.com/964671298c87387f7d5fa9900e907dceea885ee8c5ff7f0a5bf8ad04a69b26c7-image.png)

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])        
        # transpose matrix
        for i in range(n):
            for j in range(i,n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # print matrix

        for i in range(n):
            for j in range(n/2):
                matrix[i][j],matrix[i][n-1-j] = matrix[i][n-1-j],matrix[i][j]




```