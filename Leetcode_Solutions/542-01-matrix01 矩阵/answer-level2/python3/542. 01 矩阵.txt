### 解题思路

BFS

### 代码

```python []
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        ans = [[0] * n for _ in range(m)]
        d = ((0, 1), (1, 0), (0, -1), (-1, 0))
        q = {
            (i, j)
            for i, j in itertools.product(range(m), range(n))
            if matrix[i][j]
            for di, dj in d
            if 0 <= i + di < m and 0 <= j + dj < n and not matrix[i + di][j + dj]
        }
        dis = 1
        while q:
            for i, j in q:
                matrix[i][j] = 0
                ans[i][j] = dis
            dis += 1
            q = {
                (i + di, j + dj)
                for i, j in q
                for di, dj in d
                if 0 <= i + di < m and 0 <= j + dj < n and matrix[i + di][j + dj]
            }
        return ans
```