```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            if matrix[i][0] <= target <= matrix[i][-1]:
                return self.binary_search(matrix[i], target)
        return False

    def binary_search(self, row, target):
        if not row:
            return False
        left, right = 0, len(row)-1
        while left <= right:
            mid = (left+right)//2
            if row[mid] < target:
                left = mid + 1
            elif row[mid] > target:
                right = mid -1
            else:
                return True
        return False