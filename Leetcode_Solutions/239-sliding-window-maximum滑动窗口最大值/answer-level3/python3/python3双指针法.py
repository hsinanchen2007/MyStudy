```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        i,j=0,k
        res=[]
        if len(nums) == 0:
            return []
        while j<=len(nums):
            res.append(max(nums[i:j]))
            i+=1
            j+=1
        return res
```
