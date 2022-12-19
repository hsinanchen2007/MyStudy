```
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(A) == 0 or len(B) == 0:
            return [[]]

        a, c, b = len(A), len(B), len(B[0])
        AB = [[0 for _ in range(b)] for _ in range(a)]

        for i in range(a):
            for j in range(c):
                if A[i][j] != 0:
                    for k in range(b):
                        if B[j][k] != 0:
                            AB[i][k] += A[i][j] * B[j][k]

        return AB
```
