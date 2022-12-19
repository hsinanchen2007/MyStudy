利用`np.pad`，方便快捷

```python
class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import numpy as np
        board_pad = np.pad(board, ((1, 1), (1, 1)), 'constant')
        m, n = board_pad.shape
        kernel = np.array([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                ans = np.sum(board_pad[i - 1:i + 2, j - 1:j + 2] * kernel)
                if ans not in (2, 3):
                    board[i - 1][j - 1] = 0
                elif ans == 3 and board[i - 1][j - 1] == 0:
                    board[i - 1][j - 1] = 1
```
