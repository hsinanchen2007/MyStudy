
```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        return True if 1 in [target==matrix[i][j] for i in range(0,len(matrix)) for j in range(0,len(matrix[i]))] else False
```