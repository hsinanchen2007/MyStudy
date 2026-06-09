```
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        t=-sys.maxsize
        s=0
        for i in range(k):
            s+=nums[i]
        if s>t:
            t=s
        for i in range(1, len(nums)-k+1):
            s=s-nums[i-1]+nums[i+k-1]
            if s>t:
                t=s
        return t/k
```
