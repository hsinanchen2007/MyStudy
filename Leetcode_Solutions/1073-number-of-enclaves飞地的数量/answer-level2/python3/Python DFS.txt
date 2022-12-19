```python
class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        def dfs(i, j):
            nonlocal flag, cnt
            A[i][j] = 0
            cnt += 1
            for x, y in [[i - 1, j], [i, j - 1], [i, j + 1], [i + 1, j]]:
                if x < 0 or x >= len(A) or y < 0 or y >= len(A[0]):
                    flag = True
                    continue
                if A[x][y] == 1:
                    dfs(x, y)
        res = 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1:
                    cnt, flag = 0, 0
                    dfs(i, j)
                    if not flag: res += cnt
        return res

```