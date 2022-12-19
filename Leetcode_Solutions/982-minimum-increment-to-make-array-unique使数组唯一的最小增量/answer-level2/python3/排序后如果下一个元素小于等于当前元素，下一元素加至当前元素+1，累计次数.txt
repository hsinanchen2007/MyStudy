```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if A == []:
            return 0
        
        A = sorted(A)        
        s = A[0]
        c = 0
        for v in A[1:]:
            if v > s:
                s = v
                continue
                            
            c += s + 1 - v
            s += 1
        return c
