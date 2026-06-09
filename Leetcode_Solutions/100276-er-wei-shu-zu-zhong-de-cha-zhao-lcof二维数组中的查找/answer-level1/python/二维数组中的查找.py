### 解题思路
从左上角或者右下角开始遍历的话，数值只能是递增或者递减，而从右上或者左下开始遍历，数值有两种走向

### 代码

```python
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        if not matrix:
            return False
        R = len(matrix)
        C = len(matrix[0])
        i,j = 0,C-1   #从右上角或者左下角开始遍历 因为可以有两个走向
        while 0 <= i < R and 0 <= j < C:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False
```