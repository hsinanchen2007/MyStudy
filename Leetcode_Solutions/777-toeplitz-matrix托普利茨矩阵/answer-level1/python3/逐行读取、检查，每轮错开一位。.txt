```
class Solution:
    def isToeplitzMatrix(self, matrix: list) -> bool:
        res = matrix[0][:-1]
        for line in matrix[1:]:
            tmp = line[1:]
            if res != tmp:
                return False
            res = line[:-1]
        return True
```
或者，
```
class Solution:
    def isToeplitzMatrix(self, matrix: list) -> bool:
        for k in range(1, len(matrix)):
            tmp = matrix[k][1:]
            for p in range(len(tmp)):
                if tmp[p] != matrix[k-1][p]:
                    return False
        return True
```
