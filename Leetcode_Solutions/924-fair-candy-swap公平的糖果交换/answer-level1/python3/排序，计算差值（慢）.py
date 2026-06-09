
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sub=(sum(A)-sum(B))//2
        A.sort()
        B.sort()
        i, j= len(A)-1, len(B)-1
        while i>=0:
            if A[i]-sub > B[j]:
                i-=1
            else:
                while j>=0 and A[i]-sub<B[j]:
                    j-=1
                if A[i]-sub == B[j]:
                    return [A[i], B[j]]
                i-=1


