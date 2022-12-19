```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        row, col = len(mat), len(mat[0])
        res = [[0] * col for _ in range(row)]
        sum_arr = [[0] * col for _ in range(row)]
        for i in range(row):
            left = 0
            for j in range(col):
                if i == 0 and j == 0:
                    sum_arr[i][j] = mat[i][j]
                elif i == 0:
                    sum_arr[i][j] = mat[i][j] + sum_arr[i][j - 1]
                elif j == 0:
                    sum_arr[i][j] = mat[i][j] + sum_arr[i - 1][j]
                else:
                    sum_arr[i][j] = mat[i][j] + sum_arr[i - 1][j] + left
                left += mat[i][j]
        def calculate(a, b):
            if a < 0 or b < 0: return 0
            a = min(max(0, a), row - 1)
            b = min(max(0, b), col - 1)
            return sum_arr[a][b]
        for r in range(row):
            for c in range(col):
                res[r][c] = calculate(r + K, c + K) - calculate(r - K - 1, c + K) - calculate(r + K, c - K - 1) + calculate(r - K - 1, c - K -1)
        return res
```