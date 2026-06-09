class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n = sum(x for x in A)
        m = n//3
        if n%3 != 0:
            return False
        i,j = 0,len(A)-1
        a,b = A[i],A[j]
        while i<j-1:
            if a==m and b == m:
                return True
            if a!=m:
                i+=1
                a += A[i]
            if b!=m:
                j-=1
                b += A[j]
        return False