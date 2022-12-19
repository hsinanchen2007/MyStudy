```
class Solution(object):
    def prevPermOpt1(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        B = A
        k = -1
        m = float('-inf')
        for i in range(len(A)-2, -1, -1):
            for j in range(i+1, len(A)):
                if A[i] > A[j]:
                    if A[j] > m:
                        m = A[j]
                        k = j
            if k != -1:
                B[i], B[k] = B[k], B[i]
                return B
        return A 
```
