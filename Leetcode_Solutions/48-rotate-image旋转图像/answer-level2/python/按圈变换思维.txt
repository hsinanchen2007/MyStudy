
矩阵可以看成一个正方形套一个正方形组成的

```
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # 16 ms
        # 12.7 MB
        circle_num = len(matrix) // 2
        for i in range(0, circle_num):
            per_row_num = len(matrix) - 1 - i * 2

            for j in range(0, per_row_num):
                tmp = matrix[i + j][i]
                matrix[i + j][i] = matrix[i + per_row_num][i + j]
                matrix[i + per_row_num][i + j] = matrix[per_row_num - j + i][per_row_num + i]
                matrix[per_row_num - j + i][per_row_num + i] = matrix[i][per_row_num + i - j]
                matrix[i][per_row_num + i - j] = tmp
```
