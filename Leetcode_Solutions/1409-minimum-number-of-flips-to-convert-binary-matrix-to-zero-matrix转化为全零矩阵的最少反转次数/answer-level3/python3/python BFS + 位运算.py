用bfs来进行遍历， 因为一个位置不能修改两次以上(因为修改两次相当于没修改， 修改两次以上相当于修改一次)， 所以当修改完当前位置后，就继续沿着改变后的矩阵继续进行遍历


```python
from copy import deepcopy
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        row, col = len(mat), len(mat[0])
        size = row * col # The size of matrix
        
        def revert(i, j, matrix): # Revert the position
            if i < 0 or i >= row or j < 0 or j >= col:return 
            matrix[i][j] = 1 - matrix[i][j]
        
        def matrix_bits(matrix): # Transform the matrix to bits string
            res = ''
            for i in range(size):
                res += str(matrix[i // col][i % col])
            return res
        
        
        queue, visDic = [mat], [matrix_bits(mat)]
        forward = [(0, 0), (0, 1), (0, -1), (1, 0), (-1, 0)]
        res = 0
        
        while queue != []:    
            queue_length = len(queue)
            for _ in range(queue_length):
                tempMat = queue.pop(0)
                if sum(sum(tempMat, [])) == 0: # if the elements of matrix all zero.
                    return res
                
                for i in range(size):
                    tempMat_copy = deepcopy(tempMat)
                    r, c = i // col, i % col
                    for f in forward:
                        revert(r + f[0], c + f[1], tempMat_copy)
                    bits = matrix_bits(tempMat_copy)
                    if bits in visDic: continue
                    visDic.append(bits)
                    queue.append(tempMat_copy)
            res += 1
        return -1
        
```


使用一维矩阵

```python
from copy import deepcopy
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        row, col = len(mat), len(mat[0])
        size = row * col # The size of matrix
        
        def revert(i, j, matrix): # Revert the position
            if i < 0 or i >= row or j < 0 or j >= col:return 
            matrix[i * col + j] ^= 1 # XOR manipulation
        
        def matrix_bits(matrix): # Transform the matrix to bits string
            return ''.join(map(str, matrix))
        
        
        mat = [mat[i][j] for i in range(row) for j in range(col)]
        queue, visDic = [mat], [matrix_bits(mat)]
        forward = [(0, 0), (0, 1), (0, -1), (1, 0), (-1, 0)]
        res = 0
        
        while queue != []:    
            queue_length = len(queue)
            for _ in range(queue_length):
                tempMat = queue.pop(0)
                if sum(tempMat) == 0: # if the elements of matrix all zero.
                    return res
                
                for i in range(size):
                    tempMat_copy = deepcopy(tempMat)
                    r, c = i // col, i % col
                    for f in forward:
                        revert(r + f[0], c + f[1], tempMat_copy)
                    bits = matrix_bits(tempMat_copy)
                    if bits in visDic: continue
                    visDic.append(bits)
                    queue.append(tempMat_copy)
            res += 1
        return -1
```
