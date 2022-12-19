```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        re=[
            [1]
        ] if numRows > 0 else []
        for i in range(numRows-1):
            tmp=[1]
            for j in range(i):
                tmp.append(re[i][j]+re[i][j+1])
            tmp.append(1)
            re.append(tmp)
        return re
        
```
