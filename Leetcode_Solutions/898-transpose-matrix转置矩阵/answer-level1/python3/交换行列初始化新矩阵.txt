```
class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        rows = len(A)
        cols = len(A[0])
        return [[A[i][j] for i in range(rows)] for j in range(cols)]

```
