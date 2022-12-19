### 解题思路
从左下或者右上开始，比较大小即可，具体见下方代码。

### 代码

```python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix == []:
            return False
        len_1 = len(matrix)
        len_2 = len(matrix[0])
        x = len_1 - 1
        y = 0
        while x >= 0 and y < len_2:
            if matrix[x][y] == target:
                return True
            if matrix[x][y] < target:
                y += 1
            else:
                x -= 1
        return False
```