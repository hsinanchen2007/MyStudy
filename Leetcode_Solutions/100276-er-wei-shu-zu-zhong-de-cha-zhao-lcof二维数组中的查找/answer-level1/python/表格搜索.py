### 解题思路
一开始我的思路是直接遍历，但是从左上角开始的话会走一些不必要的路
仔细观察一下可以优化，如果我们取右上角作为搜索起始点，因为只有左边的数比它小，下面的数比它大，这样搜索路径会更短一些

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        row = len(matrix)
        if row == 0:
            return False
        col = len(matrix[0])
        
#         for i in range(row):
#             for j in range(col):
#                 if matrix[i][j]== target:
#                     return True
#                 if matrix[i][j] > target:
#                     break
        
#         return False
        # 如果再观察一下，就可以从右上角开始搜索
        i = 0
        j = col - 1
        while(i < row and j>=0):
            if target < matrix[i][j]:
                j -= 1
            elif target > matrix[i][j]:
                i += 1
            else:
                return True
        
        return False
```