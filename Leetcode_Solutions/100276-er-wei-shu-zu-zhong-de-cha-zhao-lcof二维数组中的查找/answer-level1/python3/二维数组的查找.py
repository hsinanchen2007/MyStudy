### 解题思路
1. 选择右上角或左下角，因为其既是最小值又是最大值，具有判断性，可以每次在数组的查找范围中剔除一行或者一列。
因此不能选左上角或右下角。

2. 很容易想到一维数组的二分查找，但是二维的二分查找会分成4个部分，剩余范围不一定是正方形，不好进行下一步的迭代。

时间复杂度：O(N+M)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        
        N = len(matrix) - 1
        M = len(matrix[0]) - 1
        
        x = 0
        y = M
        
        while x <= N and y >= 0:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] > target:
                y -= 1
            else:
                x += 1

        return False
```