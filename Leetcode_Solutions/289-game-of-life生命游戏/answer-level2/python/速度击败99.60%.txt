### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # board_copy = board.copy()
        board_copy = copy.deepcopy(board)
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                a11 = board_copy[i-1][j-1] if self.isOutOfBoard(i-1,j-1,m,n) else 0
                a12 = board_copy[i-1][j] if self.isOutOfBoard(i-1,j,m,n) else 0
                a13 = board_copy[i-1][j+1] if self.isOutOfBoard(i-1,j+1,m,n) else 0
                a21 = board_copy[i][j-1] if self.isOutOfBoard(i,j-1,m,n) else 0
                a23 = board_copy[i][j+1] if self.isOutOfBoard(i,j+1,m,n) else 0
                a31 = board_copy[i+1][j-1] if self.isOutOfBoard(i+1,j-1,m,n) else 0
                a32 = board_copy[i+1][j] if self.isOutOfBoard(i+1,j,m,n) else 0
                a33 = board_copy[i+1][j+1] if self.isOutOfBoard(i+1,j+1,m,n) else 0
                sumall = a11+a12+a13+a21+a23+a31+a32+a33
                if board_copy[i][j] == 1:
                    if sumall in [2,3]:
                        board[i][j] = 1
                    else:
                        board[i][j] = 0
                else:
                    if sumall == 3:
                        board[i][j] = 1
                    else:
                        board[i][j] = 0



    def isOutOfBoard(self, x, y, m, n) -> bool:
        return True if x>=0 and y>=0 and x<m and y<n else False



```