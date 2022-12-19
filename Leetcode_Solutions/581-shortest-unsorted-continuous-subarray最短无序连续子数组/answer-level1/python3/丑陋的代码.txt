```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        l = -1
        r = -1
        a = sorted(nums)
        n =len(nums)
        for i in range(n):
            if nums[i]!=a[i] and l ==-1:
                l = i
            if nums[n-1-i] != a[n-1-i] and r ==-1:
                r = n-1-i
        return r-l+1 if l!=-1 and r!=-1 else 0
```
