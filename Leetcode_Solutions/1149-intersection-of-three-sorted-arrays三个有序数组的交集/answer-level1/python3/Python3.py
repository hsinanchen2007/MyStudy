```
class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        arr, ret = sorted(arr1 + arr2 + arr3), []
        for i in range(len(arr)-2):
            if arr[i] * 2 == (arr[i+1] + arr[i+2]) and arr[i+1] == arr[i+2]:
                ret.append(arr[i])
                i += 3
        return ret
```
