```
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        c = range(len(matrix))
        r = range(len(matrix[0]))
        print(c,r)
        for i in r:
            colum = 0
            raw = i
            while colum < len(c) and raw < len(r):
                if matrix[0][i] != matrix[colum][raw]:
                    return False
                colum += 1
                raw += 1
        for i in c:
            colum = i
            raw = 0
            while colum < len(c) and raw < len(r):
                if matrix[i][0] != matrix[colum][raw]:
                    return False
                colum += 1
                raw += 1
        return True
```
