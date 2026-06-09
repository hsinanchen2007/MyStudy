![image.png](https://pic.leetcode-cn.com/48f304fd916f6fd296e22daae9b77dc596e5ed31ab13c931d7cd1535fc5254fa-image.png)

扫描到0，行列非0元素直接记成非数字的记号就行，然后再遍历一遍把做了记号的元素变为0。
```python []
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    for k in range(m):
                        if matrix[k][j] != 0:
                            matrix[k][j] = ''
                    for k in range(n):
                        if matrix[i][k] != 0:
                            matrix[i][k] = ''
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '':
                    matrix[i][j] = 0 
```
