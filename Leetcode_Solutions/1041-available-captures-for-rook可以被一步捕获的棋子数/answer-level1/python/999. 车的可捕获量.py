### 解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        count = 0
        x, y = 0, 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    x, y = i, j
        # 向上
        x_, y_ = x, y
        while x_ > 0 and board[x_-1][y_] != 'B':
            x_ -= 1
            if board[x_][y_] == 'p':
                count += 1
                break
        # 向下
        x_, y_ = x, y
        while x_ < len(board)-1 and board[x_+1][y_] != 'B':
            x_ += 1
            if board[x_][y_] == 'p':
                count += 1
                break
        # 向左
        x_, y_ = x, y
        while y_ > 0 and board[x_][y_-1] != 'B':
            y_ -= 1
            if board[x_][y_] == 'p':
                count += 1
                break
        # 向右
        x_, y_ = x, y
        while y_ < len(board[0])-1 and board[x_][y_+1] != 'B':
            y_ += 1
            if board[x_][y_] == 'p':
                count += 1
                break
        return count


        

```