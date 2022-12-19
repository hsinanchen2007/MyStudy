```
from collections import defaultdict
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        line = defaultdict(set)
        row = defaultdict(set)
        mat = defaultdict(set)
        for il, l in enumerate(board):
            for ir, v in enumerate(l):
                if v == ".":
                    continue
                c = 0
                if v not in line[il]:
                    line[il].add(v)
                    c += 1
                if v not in row[ir]:
                    row[ir].add(v)
                    c += 1
                if v not in mat[3*(il//3)+(ir//3)]:
                    mat[3*(il//3)+(ir//3)].add(v)
                    c += 1
                if c != 3:
                    return False
        return True
```
