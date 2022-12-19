### 解题思路
```python3
zero_index = []
        for k, mat in enumerate(matrix):
            index = []
            for j, v in enumerate(mat):
                if v == 0:
                    index.append(j)
            if index:
                matrix[k] = [0 for x in mat]
                zero_index.extend(index)

        if zero_index:
            for index in zero_index:
                for mat in matrix:
                    mat[index] = 0
```
此处撰写解题思路

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        zero_index = []
        for k, mat in enumerate(matrix):
            index = []
            for j, v in enumerate(mat):
                if v == 0:
                    index.append(j)
            if index:
                matrix[k] = [0 for x in mat]
                zero_index.extend(index)

        if zero_index:
            for index in zero_index:
                for mat in matrix:
                    mat[index] = 0
    
```