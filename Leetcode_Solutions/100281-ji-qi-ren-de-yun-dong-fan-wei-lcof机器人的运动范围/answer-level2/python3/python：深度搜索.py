```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def sum_two(a, b):
            return a % 10 + b % 10 + a // 10 + b // 10
        visited = set()
        def dfs(x, y):
            if sum_two(x, y) > k or not 0 <= x < m or not 0 <= y < n or (x, y) in visited:
                return 0
            visited.add((x,y))
            return 1 + dfs(x + 1, y) + dfs(x, y + 1)
        return dfs(0, 0)
```
