```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==0: return []
        if numRows==1: return [[1]]
        if numRows==2: return [[1],[1,1]]
        rows = [[1],[1,1]]
        for i in range(3,numRows+1):
            rowi = [0]*i
            rowi[0] = 1
            rowi[-1] = 1
            for j in range(1,i-1):
                rowi[j] = rows[i-2][j-1]+rows[i-2][j]
            rows.append(rowi)
        return rows
```
