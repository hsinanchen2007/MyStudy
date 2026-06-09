### 解题思路
转换为一维数组，然后二分查找

### 代码

```python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # 转换为一维数组，然后二分查找
        matrix_len = len(matrix)
        res = []
        for mt in matrix:
            res.extend(mt)
        low = 0
        high = len(res) - 1
        while low <= high:
            mid = (low + high) // 2
            if res[mid] == target:
                return True
            elif res[mid] > target:
                high = mid -1
            else:
                low = mid + 1
        return False
```