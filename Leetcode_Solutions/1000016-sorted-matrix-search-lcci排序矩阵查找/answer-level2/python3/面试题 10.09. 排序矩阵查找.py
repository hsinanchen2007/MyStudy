做了太多次。。

```python []
class Solution:
    def searchMatrix(self, matrix, target):
        for mat in matrix[:: -1]:
            for i in range(len(matrix[0])):
                if mat[i] > target:
                    break
                if mat[i] == target:
                    return True
        return False
```