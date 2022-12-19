思路一，库函数
```
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        return A.index(max(A))
```

思路二，二分查找
```
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        low,high = 0,len(A)-1
        while low<high:
            mid = (low+high)//2
            if A[mid-1]<A[mid]<A[mid+1]:
                low = mid+1
            elif A[mid+1]<A[mid]<A[mid-1]:
                high = mid-1
            else: 
                return mid
        return low
```
