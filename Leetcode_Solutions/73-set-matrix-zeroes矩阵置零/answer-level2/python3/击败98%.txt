```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        list1 = []
        n1 = len(matrix[0])
        for i in matrix:
            if 0 not in i:
                pass
            else:
                for j in range(n1):
                    if i[j] == 0:
                        if j not in list1:
                            list1.append(j)
                    else:
                        i[j] = 0
        if list1 == []:
            return(matrix)
        else:
            for ii in matrix:
                for a in list1:
                    ii[a] = 0
            return(matrix)
```
