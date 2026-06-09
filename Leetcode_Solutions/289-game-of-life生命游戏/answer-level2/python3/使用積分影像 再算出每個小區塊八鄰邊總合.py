### 解题思路
使用積分影像 再算出每個小區塊八鄰邊總合
積分影項可以減少 計算量

### 代码

```python3
import numpy as np
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        M = len(board)
        N = len(board[0])
        m = np.zeros((M+3, N +3))
        m[2:2+M,2:2+N] = np.array(board)

        for i in range(1, M+3):
            m[i, :] += m[i - 1, :]
        for j in range(1, N+3):
            m[:, j] += m[:, j - 1]

        for i in range(2, M+2):
            for j in range(2, N+2):
                a, b, c, d = m[i - 2, j - 2], m[i - 2, j + 1], m[i + 1, j - 2], m[i + 1, j + 1]
                a2, b2, c2, d2 = m[i - 1, j - 1], m[i - 1, j ], m[i , j - 1], m[i , j]
                summ = (d+a-b-c) - (d2+a2-b2-c2)
                if summ < 2:
                    board[i-2][j-2] = 0
                elif 2<=summ<=3 and board[i-2][j-2] == 1:  
                    board[i-2][j-2] = 1  
                elif summ > 3:  
                    board[i-2][j-2] = 0
                elif summ==3:  
                    board[i-2][j-2] = 1
        return board             




```