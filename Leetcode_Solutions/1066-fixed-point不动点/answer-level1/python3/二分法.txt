```
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        """
           一看有序数组，第一反应就是二分法
        """
        size = len(A)

        left, right = 0, size-1
        min_index = size
        while left <= right:
            mid = (left + right) // 2
            if mid == A[mid]:
                min_index = min(min_index, mid)
                right = mid - 1
                continue
            
            if mid > A[mid]:
                left = mid + 1
            else:
                right = mid - 1


        return -1 if min_index == size else min_index
```
