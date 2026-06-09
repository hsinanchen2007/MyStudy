

```python []
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        r = '|'.join(('', *map(''.join, board), '')).replace('.', '')
        c = '|'.join(('', *map(''.join, zip(*board)), '')).replace('.', '')
        i, j = r.find('R'), c.find('R')
        return (r[i - 1], r[i + 1], c[j - 1], c[j + 1]).count('p')
```

另一种解法：

```python []
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for x, y in itertools.product(range(8), repeat=2):
            if board[x][y] == 'R':
                return sum((
                    next((board[i][y] == 'p' for i in range(x + 1, 8) if board[i][y] != '.'), 0),
                    next((board[i][y] == 'p' for i in reversed(range(x)) if board[i][y] != '.'), 0),
                    next((board[x][j] == 'p' for j in range(y + 1, 8) if board[x][j] != '.'), 0),
                    next((board[x][j] == 'p' for j in reversed(range(y)) if board[x][j] != '.'), 0)
                ))
```
