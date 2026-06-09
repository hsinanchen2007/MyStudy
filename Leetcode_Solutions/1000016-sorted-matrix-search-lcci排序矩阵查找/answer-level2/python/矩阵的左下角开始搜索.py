### 解题思路
1. 从矩阵的左下角开始搜索；
2. 如果等于目标值，done；
3. 如果小于目标值，向右搜索；
4. 如果大于目标值，向左搜索；

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i ,j = len(matrix) - 1, 0
        while i >= 0 and j < len(matrix[0]):
            if target == matrix[i][j]:
                return True
            elif target > matrix[i][j]:
                j += 1
            else:
                i -= 1
            
        return False
```