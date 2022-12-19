### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        row = len(board)
        col = len(board[0])
        board_copy = [[board[row1][col1] for col1 in range(col)] for row1 in range(row)]

        # board_copy[:][:] = board[:][:]


        for i in range(row):
            for j in range(col):
                count = 0
                for x,y in [(i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j),(i+1,j+1),(i+1,j-1)]:
                    if 0<=x<row and 0<=y<col and board_copy[x][y] == 1:
                        count+=1
                if board_copy[i][j] == 0 and count == 3:
                    board[i][j] = 1
                elif board_copy[i][j] == 1 and count < 2:
                    board[i][j] = 0
                elif board_copy[i][j] == 1 and count > 3:
                    board[i][j] = 0
                        
```