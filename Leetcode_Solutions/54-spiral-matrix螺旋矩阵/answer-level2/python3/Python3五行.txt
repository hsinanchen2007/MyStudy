1. 每次取matrix的第一行
2. 将剩余部分逆时针旋转90°生成一个新的矩阵赋给matrix
3. 重复1，2直到matrix为空
```
class Solution:
    def spiralOrder(self, matrix: list) -> list:
        res = []
        while matrix:
            res.extend(matrix[0])
            matrix = [r for r in zip(*matrix[1:])][::-1]
        return res
```
