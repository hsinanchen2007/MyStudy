### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # if not matrix: return False
        # m, n = len(matrix), len(matrix[0])
        # for r in range(m - 1, -1, -1):
        #     for c in range(n):
        #         if matrix[r][c] > target:
        #             break
        #         if matrix[r][c] == target:
        #             return True
        # return False
        return target in set(sum(matrix, []))
        


```