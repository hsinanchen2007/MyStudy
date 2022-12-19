### 解题思路

二维数组遵循严格的左右单调增，上下单调增。那么就从左下或者右上进行计算。
显然的从左下开始时，对于ij，
如果m[i][j]比target大，那么就在ij的右边
如果比target小，那么就在ij的上边

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix, target):
        if len(matrix) <= 0:
            return False
        r, c = len(matrix), len(matrix[0])
        i, j = r - 1, 0
        while i >= 0 and j < c:
            if matrix[i][j] > target:
                i -= 1
            elif matrix[i][j] < target:
                j += 1
            else:
                return True
        return False
```

击败100%空间时间