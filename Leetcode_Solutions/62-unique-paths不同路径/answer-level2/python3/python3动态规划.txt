### 解题思路
python3动态规划

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        matrix = [[1]*n for _ in range(m)]

        for index_row in range(1, m):
            for index_col in range(1, n):
                matrix[index_row][index_col] = matrix[index_row-1][index_col] +\
                        matrix[index_row][index_col-1]

        return matrix[-1][-1]

```