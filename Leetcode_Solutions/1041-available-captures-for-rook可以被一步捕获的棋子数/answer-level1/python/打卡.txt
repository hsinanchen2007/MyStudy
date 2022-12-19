### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        r = len(board)
        col = len(board[0])
        for i, row in enumerate(board):
            for j, value in enumerate(row):
                if value == "R":
                    for k in reversed(range(j)): #left
                        if row[k] == "B":
                            break
                        if row[k] == 'p':
                            ans += 1
                            break
                    for k in range(j+1, col): #right
                        if row[k] == "B":
                            break
                        if row[k] == 'p':
                            ans += 1
                            break
                    for k in reversed(range(i)): #top
                        if board[k][j] == "B":
                            break
                        if board[k][j] == 'p':
                            ans += 1
                            break                    
                    for k in range(i+1, r): #botton
                        if board[k][j] == "B":
                            break
                        if board[k][j] == 'p':
                            ans += 1
                            break
                    return ans

                    
```