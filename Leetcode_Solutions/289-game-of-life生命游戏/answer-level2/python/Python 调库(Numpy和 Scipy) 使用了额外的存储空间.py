这个方法用了额外的存储空间, 不满足要求.
记录一下各种库的用法吧.
```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return 
        import numpy as np
        from scipy import signal
        np_mat = np.array(board)
        np_filter = np.ones(((3, 3)))
        np_filter[1, 1] = 0
        res = signal.convolve2d(np_mat, np_filter, mode='same').astype(int)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]:
                    if res[i, j] < 2 or res[i, j] > 3:
                        board[i][j] = 0
                else:
                    if res[i, j] == 3:
                        board[i][j] = 1
```