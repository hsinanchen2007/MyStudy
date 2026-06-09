
执行用时 : 44 ms, 在Available Captures for Rook的Python3提交中击败了90.32% 的用户

内存消耗 : 12.8 MB, 在Available Captures for Rook的Python3提交中击败了98.75% 的用户

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x = 0
        y = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    x = i
                    y = j
        count = 0
        # 向左搜索
        for i in range(y-1,-1,-1):
            if board[x][i] == 'p':
                count += 1
                break
            elif board[x][i] == 'B':
                break
        # 向右搜索
        for i in range(y+1,len(board)):
            if board[x][i] == 'p':
                count += 1
                break
            elif board[x][i] == 'B':
                break
        # 向下搜索
        for i in range(x+1,len(board[0])):
            if board[i][y] == 'p':
                count += 1
                break
            elif board[i][y] == 'B':
                break
        # 向上搜索
        for i in range(x-1,-1,-1):
            if board[i][y] == 'p':
                count += 1
                break
            elif board[i][y] == 'B':
                break
        return count
```