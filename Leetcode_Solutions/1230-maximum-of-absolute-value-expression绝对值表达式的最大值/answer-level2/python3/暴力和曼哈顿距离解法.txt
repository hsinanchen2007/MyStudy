```
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        mx = 0
        inx = [i for i in range(len(arr1))]
        for x,y in [[1,1], [1,-1], [-1,1], [-1,-1]]:
            sm = [arr1[i]+arr2[i]*x+inx[i]*y for i in range(len(arr1))]
            mx = max(mx, max(sm) - min(sm))
        return mx

```

暴力解法
```
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        mx = 0
        for i in range(len(arr1)-1):
            for j in range(i+1, len(arr1)):
                mx = max(abs(arr1[i]-arr1[j]) + abs(arr2[i]-arr2[j]) + abs(i-j), mx)
        return mx
```
