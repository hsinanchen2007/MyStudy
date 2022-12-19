### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        self.visited = [[False for _ in range(n)] for _ in range(m)]
        self.process(m, n, 0, 0 ,k)
        return sum(sum(self.visited, []))
    
    def process(self, m, n, i, j, k):
        if i < 0 or i > m - 1 or j < 0 or j > n -1 or self.getSum(i, j) > k or self.visited[i][j]:
            return
        self.visited[i][j] = True
        self.process(m, n, i - 1, j, k)
        self.process(m, n, i + 1, j, k)
        self.process(m, n, i, j - 1, k)
        self.process(m, n, i, j + 1, k)

    def getSum(self, i, j):
        return sum(map(int, str(i)+str(j)))

```