### 解题思路

有一个规律，逆序 + 转置 = 右旋 90 度，恰好可以利用 python zip

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        r = list(zip(*matrix[::-1]))
        for i in range(n):
            for j in range(n):
                matrix[i][j] = r[i][j]

```