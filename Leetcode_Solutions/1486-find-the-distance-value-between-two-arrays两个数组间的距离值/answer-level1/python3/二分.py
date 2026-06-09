分别将arr[i] - d 和 arr[i] + d对数组查找 如果两个下标相同 arr[i]是符合要求的
```
import bisect
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        res = 0
        for i in arr1:
            left = bisect.bisect_left(arr2, i- d)
            right = bisect.bisect(arr2, i + d)
            if left == right:res += 1
        return res 
```
