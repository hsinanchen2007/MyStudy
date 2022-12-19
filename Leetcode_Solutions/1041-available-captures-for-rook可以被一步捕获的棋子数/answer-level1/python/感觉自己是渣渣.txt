### 解题思路
就上下左右遍历，也太简单了吧，感觉自己是渣渣

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res = 0
        indx, indy = 0, 0
        for i in range(len(board)):
            if "R" in board[i]:
                indx = i
                indy = board[i].index("R")
                break
        changex, changey = indx - 1, indy
        while changex >= 0:
            if board[changex][changey] == "B":
                break
            if board[changex][changey] == "p":
                res += 1
                break
            changex -= 1
        changex = indx + 1
        while changex < len(board):
            if board[changex][changey] == "B":
                break
            if board[changex][changey] == "p":
                res += 1
                break
            changex += 1
        changex, changey = indx, indy
        while changey >= 0:
            if board[changex][changey] == "B":
                break
            if board[changex][changey] == "p":
                res += 1
                break
            changey -= 1
        changex, changey = indx, indy + 1
        while changey < len(board[0]):
            if board[changex][changey] == "B":
                break
            if board[changex][changey] == "p":
                res += 1
                break
            changey += 1
        return res

```