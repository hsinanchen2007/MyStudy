```
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        l = len(arr)
        dp1 = [arr[0] for _ in range(l)]
        dp2 = [arr[0] for _ in range(l)]
        ret = arr[0]
        
        for i in range(1, l):
            dp1[i] = max(arr[i], dp1[i-1]+arr[i])
            dp2[i] = max(dp1[i-1], dp2[i-1] + arr[i])
            ret = max(ret, dp1[i], dp2[i])
        return ret
```
