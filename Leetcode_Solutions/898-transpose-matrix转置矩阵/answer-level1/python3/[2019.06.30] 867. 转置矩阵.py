B是A 置换后的结果  A[i][j] = B[j][i]
!!! 需要创建一个空的矩阵是j行 i列的

```
class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        # 行, 列
        row, col = len(A), len(A[0])

        i, j = 0, 0
        # A[i][j] = B[j][i] 需要建立一个维度确认的空矩阵
        B = []
        for _ in xrange(col):
          B += [[None] * row]

        # 需要转置: i为行( < col), j为列( < row)
        while(i < col):
          while(j < row):
            B[i][j] = A[j][i]
            j += 1
          i += 1
          j = 0

        return B
```
