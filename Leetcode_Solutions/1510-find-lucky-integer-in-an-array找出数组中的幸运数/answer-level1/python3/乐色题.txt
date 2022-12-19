```
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        a=collections.Counter(arr)
        ans=float("-inf")
        for i in a.keys():
            if i==a[i]:
                ans=max(ans,i)
        return ans if ans!=float("-inf") else -1
```
