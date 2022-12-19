```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:

        self.count = 0
        self.visited = [[False] * n for _ in range(m)]
        self.d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        self._dfs(0, 0, m, n, k)
        return self.count

    def _dfs(self, i, j, m, n, k):
        # 一定要先check_valid要不然_get_num会传入负值
        if not self._chech_valid(i, j, m, n) or \
            self._get_num(i) + self._get_num(j) > k or \
            self.visited[i][j]:
            return

        self.visited[i][j] = True  # 遍历过的标志，也就是只记一次数
        self.count += 1
        for _d in self.d:
            new_i = i + _d[0]
            new_j = j + _d[1]
            self._dfs(new_i, new_j, m, n, k)

    def _get_num(self, n):
        res = 0
        while n:
            res += n % 10
            n //= 10
        return res

    def _chech_valid(self, i, j, m, n):
        return 0 <= i < m and 0 <= j < n
```