```
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        res = []
        tmp = []
        for j in range(len(A[0])):
            for i in range(len(A)):
                tmp.append(A[i][j])
            res.append(tmp)
            tmp = []
        return res
            
```
