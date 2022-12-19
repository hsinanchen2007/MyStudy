### 解题思路
这道题可以类比深度学习的CNN运算，所以下面用Numpy来进行计算。

### 代码

```python
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        import numpy as np
        ext_board = np.array(board)
        ext_board = np.pad(ext_board, 1, 'constant')
        kernel = np.array([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
        m, n = ext_board.shape
        # print(m, n)
        for i in range(m - 2):
            for j in range(n - 2):
                num = np.sum(ext_board[i:i + 3, j:j + 3] * kernel)
                if (num < 2 or num > 3) and board[i][j]:
                    board[i][j] = 0 # 1 -> 0
                elif num == 3 and board[i][j] == 0:
                    board[i][j] = 1 # 0 -> 1

        return board
```