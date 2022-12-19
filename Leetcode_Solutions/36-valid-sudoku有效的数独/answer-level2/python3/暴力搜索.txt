### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        q=0
        for i in range(9):
            for j in range(9):
                k=j+1
                while k<9:
                    if (board[i][j]!=".")&(board[i][j]==board[i][k]):
                       q=-1
                    k+=1
        for i in range(9):
            for j in range(9):
                k=j+1
                while k<9:
                    if (board[j][i]!=".")&(board[j][i]==board[k][i]):
                       q=-1
                    k+=1


        for a in range(3):
            for b in range(3):
                for i in range(3):
                    for j in range(3):
                        for m in range(3):
                            for n in range(3):
                                if (board[i+a*3][j+b*3]!=".")&(board[i+a*3][j+b*3]==board[m+a*3][n+b*3])&(m!=i or n!=j):
                                    q=-1
        if q==0:
            return True
        else:
            return False
```