```
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n1 = len(arr)
        max1 = max(arr)
        first = 0
        result = []
        if n1 == 1:
            return([-1])
        while first <= n1:
            if len(arr[first+1:]) == 1:
                result.append(arr[first+1])
                result.append(-1)
                return(result)
            elif len(arr[first+1:]) == 0:
                result.append(-1)
                return(result)
            max1 = max(arr[first+1:])
            index1 = arr[first+1:].index(max1)
            for i in range(index1 + 1):
                result.append(max1)
            first = index1+1+first
```
