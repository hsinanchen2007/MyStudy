### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        Rx,Ry = 0,0
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'R':
                    Rx,Ry = i,j
        countl = 0
        for j in range (Ry):
            if board[Rx][j] == 'p':
                countl = 1
                continue
            if board[Rx][j] == 'B':
                countl = 0
        countr = 0
        for j in range (Ry+1,len(board[Rx])):
            if board[Rx][j] == 'B':
                break
            elif board[Rx][j] == 'p':
                countr = 1
        countu = 0
        for i in range (Rx):
            if board[i][Ry] == 'p':
                countu = 1
                continue
            if board[i][Ry] == 'B':
                countu = 0
        countd = 0
        for i in range (Rx,len(board)):
            if board[i][Ry] == 'B':
                break
            elif board[i][Ry] == 'p':
                countd = 1
        return countl+countr+countu+countd
                
            



```