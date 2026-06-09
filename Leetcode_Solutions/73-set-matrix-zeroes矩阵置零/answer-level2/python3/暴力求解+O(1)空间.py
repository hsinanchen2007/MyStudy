第一种方法是直接暴力求解，先用列表记录所有0元素的行号和列号，再针对列表里的所有元素按行号和列号将原数组元素的行和列置为0。
时间复杂度_O(MxN)_空间复杂度_O(MxN)_。

```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        n = len(matrix[0])
        res = []
        for i in range(l):
            for j in range(n):
                if matrix[i][j] == 0:
                    res.append([i, j])
        for tmp in res:
            x = tmp[0]
            y = tmp[1]
            for i in range(n):
                matrix[x][i] = 0
            for i in range(l):
                matrix[i][y] = 0
```

第二种方法是遍历一次矩阵中的所有元素，如果遇到元素为0，则分别将这个0元素所在的行和列中所有非0元素替换为指定字符，最后再遍历一次矩阵，将所有的指定字符替换为0。
时间复杂度_O(MxNx(M+N))_空间复杂度_O(1)_

```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        n = len(matrix[0])
        for i in range(l):
            for j in range(n):
                if matrix[i][j] == 0:
                    for p in range(n):
                        if matrix[i][p] != 0:
                            matrix[i][p] = 'a'  #设置指定字符
                    for q in range(l):
                        if matrix[q][j] != 0:
                            matrix[q][j] = 'a'
        for i in range(l):
            for j in range(n):
                if matrix[i][j] == 'a':
                    matrix[i][j] = 0
```