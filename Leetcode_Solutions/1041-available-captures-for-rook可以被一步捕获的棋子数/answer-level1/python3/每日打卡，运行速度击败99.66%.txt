
### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:

        result = 0
        
        # find position of rook
        r_x = 0
        r_y = 0
        while r_y < len(board):
            if 'R' in board[r_y]:
                break
            r_y += 1
        r_x = board[r_y].index('R')

        # search left
        move_x = r_x
        while move_x > 0:
            move_x -= 1
            if board[r_y][move_x] == 'B':
                break
            if board[r_y][move_x] == 'p':
                result += 1
                break

        # search right
        move_x = r_x
        while move_x < len(board[r_y])-1:
            move_x += 1
            if board[r_y][move_x] == 'B':
                break
            if board[r_y][move_x] == 'p':
                result += 1
                break

        del move_x

        # search up
        move_y = r_y
        while move_y > 0:
            move_y -= 1
            if board[move_y][r_x] == 'B':
                break
            if board[move_y][r_x] == 'p':
                result += 1
                break

        # search down
        move_y = r_y
        while move_y < len(board) - 1:
            move_y += 1
            if board[move_y][r_x] == 'B':
                break
            if board[move_y][r_x] == 'p':
                result += 1
                break

        print('\n'.join(['\t'.join(i) for i in board]))

        return(result)
```