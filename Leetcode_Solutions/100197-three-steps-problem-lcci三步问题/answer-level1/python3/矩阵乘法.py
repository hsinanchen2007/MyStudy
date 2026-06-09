### 解题思路
此处撰写解题思路

### 代码

```python3
"""
A = [
    [1,1,1],
    [1,0,0],
    [0,1,0]
]
B = [
    [x3]
    [x2]
    [x1]
]
as
[[x4],   
 [x3], = A * B
 [x2]]

m = n - 3
 [[x(n)],
  [x(n-1)],  = (A**(m)) * B  = ((A**(m/2))**2)*(A**(m%2)) * B = (((A**(m/4))**2)**2)*A(**(m%2))*B = ...
  [x(n-2)]]
"""

class Solution:
    def waysToStep(self, n: int) -> int:
        if n <= 0:return 0
        if n <= 2:return n
        if n <= 3:return 4
        A = [[1,1,1],[1,0,0],[0,1,0]]
        B = [[4],[2],[1]]
        m = n - 3
        ret = self.matrixTimes(self.matrixF(A,m),B)
        return ret[0][0] % 1000000007

    def matrixTimes(self,A:List[List[int]],B:List[List[int]])->List[List[int]]:
        Ar = len(A)
        Ac = len(A[0])
        Br = len(B)
        Bc = len(B[0])
        ret = [[sum([A[r][k]*B[k][c] for k in range(Ac)]) for c in range(Bc)] for r in range(Ar)]
        return ret

    def matrixF(self,A:List[List[int]],b:int)->List[List[int]]:
        if b <= 0:
            r = len(A)
            c = len(A[0])
            ret = [[0 for _ in range(c)] for _ in range(r)]
            for i in range(min(r,c)):
                ret[i][i] = 1
            return ret
        if b == 1:
            return A
        if b == 2:
            return self.matrixTimes(A,A)
        if b > 2:
            Ai = self.matrixF(A,int(b/2))
            Ai = self.matrixF(Ai,2)
            Aj = self.matrixF(A,b%2)
            return self.matrixTimes(Ai,Aj)




```