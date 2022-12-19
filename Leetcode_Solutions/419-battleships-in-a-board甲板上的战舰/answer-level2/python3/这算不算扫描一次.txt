```
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        num, i = 0, 0
        if not board:
            return num
        n, m = len(board), len(board[0])
        while i<n:
            j = 0
            while j<m:
                if board[i][j]=='X':
                    if i>0 and j>0:
                        if board[i-1][j]=='.' and board[i][j-1]=='.':
                            num = num+1
                    if i==0 and j>0:
                        if board[i][j-1]=='.':
                            num = num+1
                    if i>0 and j==0:
                        if board[i-1][j]=='.':
                            num = num+1
                    if i==0 and j==0:
                        num = num+1
                j += 1
            i += 1    
        return num   
```
