```
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        dictB = {}
        for i in range(len(B)):
            dictB[B[i]] = i
        res = []
        for i in range(len(A)):
            if A[i] in dictB:
                res.append(dictB[A[i]])
            
        return res
```
