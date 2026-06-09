对不起，跟大佬比快比不过，比短我还比不过吗？
```python
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        return not (True in [matrix[i][:-1] != matrix[i+1][1:] for i in range(len(matrix)-1)])
```