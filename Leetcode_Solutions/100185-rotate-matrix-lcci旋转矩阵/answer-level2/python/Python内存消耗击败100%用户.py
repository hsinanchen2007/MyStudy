思路就是先对矩阵转置，之后对每一行内容取反。

```
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # 获取列的长度，因为行列相等
        n = len(matrix[0])
        # 对矩阵进行转置操作
        for i in range(n):
            for j in range(i, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
        # print(matrix)
        # 转置后，对每一行进行取反
        for i in range(n):
            matrix[i].reverse()
```