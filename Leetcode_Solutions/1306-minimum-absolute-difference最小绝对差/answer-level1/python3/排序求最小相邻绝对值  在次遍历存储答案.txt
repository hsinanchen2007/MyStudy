```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        #
        ret = []
        arr.sort()
        min_abs = arr[1] - arr[0] 
        for i in range(1,len(arr)):
            min_abs = min(arr[i]-arr[i-1],  min_abs )

        for i in range(1,len(arr)):
            if arr[i]-arr[i-1] == min_abs:
                ret.append([arr[i-1],arr[i]])
        return ret 
```
