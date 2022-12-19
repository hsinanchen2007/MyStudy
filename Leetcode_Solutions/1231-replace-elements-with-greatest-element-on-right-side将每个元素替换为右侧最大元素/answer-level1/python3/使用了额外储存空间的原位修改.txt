```
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        temp = arr.copy()
        for i in range(len(arr)-1,0,-1):
            arr[i-1] = max(arr[i], temp[i])
        arr[-1] = -1
        return arr
```
