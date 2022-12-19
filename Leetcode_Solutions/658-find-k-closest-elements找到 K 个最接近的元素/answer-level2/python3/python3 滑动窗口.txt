```
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        s=sum(abs(arr[i]-x) for i in range(k))
        res=arr[:k]
        best=s
        for i in range(k,len(arr)):
            s += abs(arr[i]-x)-abs(arr[i-k]-x)
            if s < best:
                best = s
                res = res[1:] + [arr[i]]
        return res
```
