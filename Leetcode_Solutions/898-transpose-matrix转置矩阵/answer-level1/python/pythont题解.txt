```
class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(A)
        colums = len(A[0])
        L = []
        for i in range(colums):
            L.append([])
        for i in range(row):
            for j in range(colums):
                L[j].append(A[i][j])
        return L
```
