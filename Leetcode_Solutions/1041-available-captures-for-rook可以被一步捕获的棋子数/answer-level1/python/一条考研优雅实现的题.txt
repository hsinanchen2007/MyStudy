### 解题思路
恶心到了自己。。。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        count = 0
        x = y = 0
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == "R":
                    x = i
                    y = j
                    break
        tmp = x - 1
        while tmp >= 0:
            if board[tmp][y] == 'p':
                count += 1
                break
            if board[tmp][y] == 'B':
                break
            tmp -= 1

        tmp = x + 1
        while tmp < len(board):
            if board[tmp][y] == 'p':
                count += 1
                break
            if board[tmp][y] == 'B':
                break
            tmp += 1

        tmp = y - 1
        while tmp >= 0:
            if board[x][tmp] == 'p':
                count += 1
                break
            if board[x][tmp] == 'B':
                break
            tmp -= 1

        tmp = y + 1
        while tmp < len(board):
            if board[x][tmp] == 'p':
                count += 1
                break
            if board[x][tmp] == 'B':
                break
            tmp += 1
        
        return count
```