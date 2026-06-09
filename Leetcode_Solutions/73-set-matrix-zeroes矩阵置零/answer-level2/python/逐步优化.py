### 解题思路

第一种想法，创建一个新的大小相同的矩阵，然后扫描标记哪些位置有零，然后第二次扫描直接置零

第二种想法，由于只需要记录哪些行哪些列出现了0，所以不需要`m*n`的空间，只需要`m+n`的空间来记录

第三种想法，这`m+n`的空间可不可以从矩阵中挤出来，答案是可以的。利用矩阵的两侧的值记录即可。不过注意角落的值可能需要单独

拿一个量来存。这样就实现了`O(1)`的空间复杂度

时间复杂度`O(n*m)`

### 代码

```python3
class Solution:
    def setZeroes(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n == 0:
            return
        m = len(matrix[0])

        t = None
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    if j == 0:
                        t = 0
                    else:
                        matrix[0][j] = 0
        for i in range(1, n):
            if matrix[i][0] == 0:
                matrix[i] = [0] * m

        for i in range(1, m):
            if matrix[0][i] == 0:
                for j in range(1, n):
                    matrix[j][i] = 0

        if matrix[0][0] == 0:
            matrix[0] = [0] * m

        if t == 0:
            for i in range(0, n):
                matrix[i][0] = 0
```