```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r=[{} for i in range(9)]
        c=[{} for i in range(9)]
        b=[{} for i in range(9)]
        for i in range(9):
            for j in range(9):
                t=i//3*3+j//3
                v=board[i][j]
                if v=='.':
                    continue
                v=int(v)
                r[i][v]=r[i].get(v,0)+1
                if r[i][v]>1:
                    return False
                c[j][v]=c[j].get(v,0)+1
                if c[j][v]>1:
                    return False
                b[t][v]=b[t].get(v,0)+1
                if b[t][v]>1:
                    return False
        return True

```
