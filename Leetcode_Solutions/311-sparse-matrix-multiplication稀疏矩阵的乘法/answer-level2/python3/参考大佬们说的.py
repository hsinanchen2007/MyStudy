```
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        C = [[0 for j in range(len(B[0]))] for i in range(len(A))]
        A_0 = set()
        B_0 = set()
        for i  in range(len(A)):
            if not any(A[i]):
                A_0.add(i)
        for i  in range(len(B[0])):
            if not any([B[j][i]for j in range(len(B[0]))]):
                B_0.add(i)
        
        
        for i in range(len(A)):
            if i in A_0:
                continue
            for j in range(len(B[0])):
                if j in B_0:
                    continue
                sum1 = 0 
                for k in range(len(A[0])):
                    sum1+=A[i][k]*B[k][j]
                C[i][j] = sum1
        return C
```
