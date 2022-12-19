### 解题思路
从右上角往左下角遍历相当于不均等的二分法

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0:
            return False
        j=len(matrix[0])-1
        i=0
        while i<len(matrix) and j>=0:
            if target>matrix[i][j]:
                i+=1
            elif target==matrix[i][j]:
                return True
            else:
                j-=1
        return False
```