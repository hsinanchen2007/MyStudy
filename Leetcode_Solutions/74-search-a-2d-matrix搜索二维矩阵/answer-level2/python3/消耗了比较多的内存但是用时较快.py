### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        n_ = 0
        for i in range(n-1):
            if target<=matrix[0][-1]:
                n_ = 0
                break
            elif matrix[i][0]<=target and matrix[i+1][0]>target:
                n_ = i
                break
            elif target >=matrix[-1][0]:
                n_ = n-1
                break
        if target in matrix[n_]:
            return True
        else:
            return False

```