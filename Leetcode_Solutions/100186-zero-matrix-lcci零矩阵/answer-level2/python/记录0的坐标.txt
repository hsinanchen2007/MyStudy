![2.PNG](https://pic.leetcode-cn.com/68d35167f36f62b25fae2e37e9e0e9626ece7d460d6474b026ef6e32ac34f2ba-2.PNG)

```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        # 记录0的坐标
        temp = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    temp.append((i,j))

        for i,j in temp:
            for k in range(m): 
                # 所在列设全0
                matrix[k][j] = 0
            for l in range(n):
                # 所在行设全0
                matrix[i][l] = 0

        return matrix
```
