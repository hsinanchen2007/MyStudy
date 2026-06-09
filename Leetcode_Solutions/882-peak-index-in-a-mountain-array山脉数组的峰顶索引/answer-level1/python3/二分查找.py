### 解题思路

二分查找

时间复杂度`O(log n)`

### 代码

```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        l = 0
        r = len(A) - 1
        while l < r:
            mid = l + r + 1>> 1
            if A[mid] > A[mid - 1] and A[mid] > A[mid + 1]:
                return mid
            if A[mid - 1] < A[mid]:
                l = mid
            else:
                r = mid - 1
        return l
```