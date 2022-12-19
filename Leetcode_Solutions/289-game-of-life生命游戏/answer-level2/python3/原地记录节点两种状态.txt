### 解题思路
-1记录1变成1
2记录0变成1

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        neighbors = [(1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1)]

        rows = len(board)
        cols = len(board[0])
        for row in range(rows):
            for col in range(cols):
                nei_live = 0
                for k in neighbors:
                    x = row + k[0]
                    y = col + k[1]
                    if 0<=x<rows and 0<=y<cols and abs(board[x][y]) == 1:
                        nei_live += 1
                if board[row][col] == 1 and (nei_live < 2 or nei_live > 3):
                    board[row][col] = -1
                if board[row][col] == 0 and nei_live == 3:
                    board[row][col] = 2
        for row in range(rows):
            for col in range(cols):
                if board[row][col] > 0:
                    board[row][col] = 1
                else:
                    board[row][col] = 0
```