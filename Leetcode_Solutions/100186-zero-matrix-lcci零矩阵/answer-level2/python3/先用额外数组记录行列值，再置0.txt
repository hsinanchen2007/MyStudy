### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        mem = [[False for _ in range(len(matrix))], [False for _ in range(len(matrix[0]))]]
        def cross_search(i, j, mem=mem):
            if matrix[i][j] == 0:
                mem[0][i] = True
                mem[1][j] = True


        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                cross_search(i, j)
        for i, b in enumerate(mem[0]):
            if b:
                matrix[i] = [0 for _ in range(len(matrix[0]))]
        for j, b in enumerate(mem[1]):
            if b:
                for i in range(len(matrix)):
                    matrix[i][j] = 0
            

        
        
```