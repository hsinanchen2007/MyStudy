```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        centers = set([(1,1),(1,4),(1,7),(4,1),(4,4),(4,7),(7,1),(7,4),(7,7)])
            
        for i in range(9):
            t = board[i]
            set1 = set()
            for k in t:
                if  k!="." and k in set1:
                    return False
                else:
                    set1.add(k)
            t = []
            for j in range(9):
                if (j,i) in centers:
                    t1 = [board[j][i],board[j][i-1],board[j][i+1],
                            board[j-1][i],board[j-1][i-1],board[j-1][i+1],
                            board[j+1][i],board[j+1][i-1],board[j+1][i+1]]
                    set1 = set()
                    for k in t1:
                        if  k!="." and k in set1:
                            return False
                        else:
                            set1.add(k)
                if board[j][i]!=".":
                    t.append(board[j][i])
            set1 = set()
            for k in t:
                if  k!="." and k in set1:
                    return False
                else:
                    set1.add(k)
        return True
            
        
        
```
