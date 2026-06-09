### 解题思路
先找到rook的位置，然后向四个方向遍历，看碰到的第一个棋子是不是pawn，是就+1。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        r = 0
        b = False
        #找到R
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == "R":
                    b = True
                    break
            if b :
                break
        #向下
        for i2 in range(i+1,len(board)):
            if board[i2][j]== "p":
                r += 1
                break
            elif board[i2][j] == "B":
                break
        #向上
        for i2 in range(i-1,-1,-1):
            if board[i2][j]== "p":
                r += 1
                break
            elif board[i2][j] == "B":
                break
        #向左
        for j2 in range(j-1,-1,-1):
            if board[i][j2]== "p":
                r += 1
                break
            elif board[i][j2] == "B":
                break
        
        #向右
        for j2 in range(j+1,len(board[i])):
            if board[i][j2]== "p":
                r += 1
                break
            elif board[i][j2] == "B":
                break
        
        return r
```