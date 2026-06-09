### 解题思路
将整个矩阵展开，使用数列二分查找的方式

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        longth = len(matrix) * len(matrix[0])
        if longth == 1:
            if matrix[0][0] == target:
                return True
            else:
                return False
        start = 0
        end = longth - 1
        while(start<=end):
            i = (start+end) // 2
            if i <len(matrix[0]):
                curval = matrix[0][i]
            else:
                curval = matrix[i//len(matrix[0])][i%len(matrix[0])]
            if curval == target:
                return True
            elif curval < target:
                start = i + 1
            else:
                end = i - 1
        return False

            
```