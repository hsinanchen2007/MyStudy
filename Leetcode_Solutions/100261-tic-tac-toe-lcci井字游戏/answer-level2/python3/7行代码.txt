### 解题思路
python的any好用

### 代码

```python
class Solution:
    def tictactoe(self, board: List[str]) -> str:
        n = len(board)
        for char in ('X', 'O'):
            if any(board[r] == char * n for r in range(n)): return char
            if any(''.join([board[r][c] for r in range(n)]) == char * n for c in range(n)): return char
            if ''.join([board[r][r] for r in range(n)]) == char * n: return char
            if ''.join([board[r][n - r - 1] for r in range(n)]) == char * n: return char
        return 'Pending' if any(' ' in b for b in board) else 'Draw'
```