```
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        rs=[]
        for i in range(A.__len__()):
            rs.append(B.index(A[i]))
        return rs
```