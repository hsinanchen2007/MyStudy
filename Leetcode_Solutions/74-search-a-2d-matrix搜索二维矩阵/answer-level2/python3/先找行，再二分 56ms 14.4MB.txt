### 解题思路
先找行，再二分

### 代码

```python3
# https://leetcode-cn.com/problems/search-a-2d-matrix/
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        if not matrix[0]:
            return False
        if not matrix[0][0] <= target <= matrix[-1][-1]:
            return False
        m = len(matrix)
        n = len(matrix[0])
        if m == 1:
            row = matrix[0]
            left = 0
            right = len(row) - 1
            if row[left] == target or row[right] == target:
                return True
            if not row[left] < target < row[right]:
                return False
            while left + 2 <= right:
                mid = (left + right) // 2
                if row[mid] == target:
                    return True
                elif row[mid] < target:
                    left = mid
                else:
                    right = mid
            return False
        if n == 1:
            row = [row[0] for row in matrix]
            left = 0
            right = len(row) - 1
            if row[left] == target or row[right] == target:
                return True
            if not row[left] < target < row[right]:
                return False
            while left + 2 <= right:
                mid = (left + right) // 2
                if row[mid] == target:
                    return True
                elif row[mid] < target:
                    left = mid
                else:
                    right = mid
            return False
        i = 0
        for i in range(len(matrix)):
            if matrix[i][0] == target:
                return True
            if matrix[i][0] < target:
                continue
            else:
                i -= 1
                break
        row = matrix[i]
        left = 1
        right = len(row) - 1
        if row[left] == target or row[right] == target:
            return True
        if not row[left] < target < row[right]:
            return False
        while left + 2 <= right:
            mid = (left + right) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                left = mid
            else:
                right = mid
        return False

```