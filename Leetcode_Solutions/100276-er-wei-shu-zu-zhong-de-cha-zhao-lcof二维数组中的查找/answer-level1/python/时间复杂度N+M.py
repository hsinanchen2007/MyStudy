### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        col = 0
        row = len(matrix)-1
        while row >= 0 and col <= (len(matrix[0])-1):
                if matrix[row][col] > target:
                    row -= 1
                elif matrix[row][col] < target:
                    col += 1
                else :
                    return True
        return False






```