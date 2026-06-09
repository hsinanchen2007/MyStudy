```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # find which line it's: O(logM)
        # find which column it's: O(logN)
        # Time complexity: O(max(logM, logN))
        # Space complexity: O(1)
        if len(matrix) == 0 or len(matrix[0]) == 0:  return False
        row = self.getRow(matrix, target)
        if row < 0 or row >= len(matrix): return False
        return self.isExist(matrix[row], target)
    

    def getRow(self, matrix, target) -> int:
        l, r = 0, len(matrix) - 1
        while l <= r:
            mid = (l + r) >> 1
            if matrix[mid][-1] == target:
                return mid
            elif matrix[mid][-1] < target:
                l = mid + 1
            else:
                r = mid - 1
        return l
            

    def isExist(self, arr, target) -> bool:
        index = bisect.bisect_left(arr, target)
        if index < len(arr) and arr[index] == target: return True
        else: return False
```