### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row=len(matrix)
        if row==0:
            return False
        col=len(matrix[0])

        i=0
        j=col-1
        while i<row and j>-1:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                j=j-1
            else:
                i=i+1
        return False
```