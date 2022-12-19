### 解题思路
跟54题差不多

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # n = len(matrix)
        # # 水平翻转
        # for i in range(n//2):
        #     for j in range(n):
        #         matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
        # # 对角线翻转
        # for i in range(n):
        #     for j in range(i):
        #         matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        n = len(matrix)
        r = [*zip(*matrix[::-1])]
        for i in range(n):
            for j in range(n):
                matrix[i][j] = r[i][j]
```