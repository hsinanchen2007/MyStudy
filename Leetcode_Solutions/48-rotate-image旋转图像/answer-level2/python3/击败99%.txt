```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        list1 = []
        for i in matrix:
            list1.append(i[:])
        n1 = len(matrix)
        for j in range(n1):
            for k in range(n1):
                matrix[j][k] = list1[k][j]
            matrix[j].reverse()
        #return(list1,matrix)
```
