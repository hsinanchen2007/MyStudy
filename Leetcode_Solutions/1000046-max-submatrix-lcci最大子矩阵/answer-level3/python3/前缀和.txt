按列做前缀和。依次将每一行作为起始行，在确定起始行后，从起始行开始遍历至最后一行。
这样就相当于遍历了matrix的所有子矩阵，将前缀和保存在数组里，就可将问题转化为一维的最大子数组和问题。
```
class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        m, n, res, rescood = len(matrix), len(matrix[0]), float('-inf'), []
        for cur in range(m):     `起始行`
            colsum = [0] * n
            for i in range(cur, m):
                for j in range(n):
                    colsum[j] += matrix[i][j]
                rowsum = 0
                lefttop = [cur, 0]
                for k in range(n):
                    if rowsum <0: 
                        rowsum = 0
                        lefttop = [cur, k]
                    rowsum += colsum[k]
                    if rowsum > res:
                        rescood = lefttop + [i, k]
                        res = rowsum
        return rescood
```
