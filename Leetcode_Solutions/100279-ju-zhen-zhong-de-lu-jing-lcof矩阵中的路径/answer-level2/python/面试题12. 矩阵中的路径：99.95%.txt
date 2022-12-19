### python dfs

![image.png](https://pic.leetcode-cn.com/da74602cf0a201c24d6fc25379b8db672aa76aba20c8332e3b980e50ba5064b7-image.png)

语法糖用到了极致了，统计剪枝剪掉了大部分的`False`。

```python []
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if collections.Counter(word) - collections.Counter(itertools.chain(*board)):
            return False
        m, n, l = len(board), len(board[0]), len(word)
        d = ((0, 1), (1, 0), (0, -1), (-1, 0))
        def f(i, j, t):
            if t == l - 1:
                return board[i][j] == word[-1]
            v, board[i][j] = board[i][j], ''
            return any(
                0 <= (x := i + r) < m and \
                0 <= (y := j + c) < n and \
                board[x][y] == word[t + 1] and \
                f(x, y, t + 1)
                for r, c in d
            ) or board[i].__setitem__(j, v)
        return any(
            f(i, j, 0) 
            for i, j in itertools.product(range(m), range(n)) 
            if board[i][j] == word[0]
        )
```