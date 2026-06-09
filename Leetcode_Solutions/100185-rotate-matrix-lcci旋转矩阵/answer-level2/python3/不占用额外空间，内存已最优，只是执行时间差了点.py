执行用时 :
40 ms
, 在所有 Python3 提交中击败了
59.80%
的用户
内存消耗 :
13.4 MB
, 在所有 Python3 提交中击败了
100.00%
的用户

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        # 沿右上到左下对角线翻转（为什么不用另一条对角线自己体会）
        for i in range(n):
            for j in range(n - i - 1):
                matrix[i][j] += matrix[n - j - 1][n - i - 1]    # a -> a+b
                matrix[n - j - 1][n - i - 1]  = matrix[i][j] - matrix[n - j - 1][n - i - 1]  # b -> a (a+b-b)
                matrix[i][j] -= matrix[n - j - 1][n - i - 1]
        # 按行倒序
        for i in range(n // 2):
            for j in range(n):
                matrix[i][j] += matrix[n - i - 1][j]
                matrix[n - i - 1][j] = matrix[i][j] - matrix[n - i - 1][j]
                matrix[i][j] -= matrix[n - i - 1][j]
```

如果可以用numpy，根本没那么多麻烦事hh