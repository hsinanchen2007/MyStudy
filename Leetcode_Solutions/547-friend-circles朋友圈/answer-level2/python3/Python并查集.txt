# 操作起来``
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        A = {i:{i} for i in range(n)}
        ans = 0
        for i in range(n):
            for j in range(n):
                if A[i] != A[j] and M[i][j] == 1:
                    A[i] |= A[j]
                    for k in A[j]:
                        A[k] = A[i]
                    ans +=1
        return n - ans
                
    
    1.