### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        n = len(board)
        pCt = 0
        for i in range(n):
            for j in range(n):
                if board[i][j] == 'R':
                    u,d,l,r = i,i,j,j
                    while u>0:
                        if board[u][j] == 'p':
                            pCt += 1
                            break
                        elif board[u][j] == 'B':
                            break
                        u-=1
                    while d<n:
                        if board[d][j] == 'p':
                            pCt += 1
                            break
                        elif board[d][j] == 'B':
                            break
                        d+=1
                    while l>0:
                        if board[i][l] == 'p':
                            pCt += 1
                            break
                        elif board[i][l] == 'B':
                            break
                        l-=1
                    while r<n:
                        if board[i][r] == 'p':
                            pCt += 1
                            break
                        elif board[i][r] == 'B':
                            break
                        r+=1
        return pCt

```