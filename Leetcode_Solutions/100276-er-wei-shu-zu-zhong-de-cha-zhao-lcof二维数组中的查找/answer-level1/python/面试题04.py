### 解题思路
通过左下角标志法来求解
1.将左下角的数设立为flag，`if flag < target:将列加一  if flag > target:将行减一 也就是所在的行消去`

### 代码

```python
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = len(matrix) - 1
        j =0 
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] > target:
                 i = i -1
            elif matrix[i][j] < target:
                j = j + 1
            else:
                return True
        return False
```