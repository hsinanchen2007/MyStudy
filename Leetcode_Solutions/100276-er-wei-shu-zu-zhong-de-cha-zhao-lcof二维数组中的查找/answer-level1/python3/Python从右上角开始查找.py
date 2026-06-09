### 解题思路
首先去除特殊情况。
然后从右上角开始查找，如当前值大于target，列数-1.如当前值小于target，行数+1。

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix == [[]] or matrix == []:
            return False
        
        if target < matrix[0][0]:
            return False
        
        n = len(matrix)
        m = len(matrix[0])
        i = 0
        j = m-1
        while i < n and j > -1:
                if target == matrix[i][j]:
                    return True
                elif target > matrix[i][j]:
                    i += 1
                elif target < matrix[i][j]:
                    j -= 1
        return False
```