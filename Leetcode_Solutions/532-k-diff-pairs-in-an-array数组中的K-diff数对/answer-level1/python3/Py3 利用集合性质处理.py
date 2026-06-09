**利用集合元素互异性去重，来找到无重复对.**
```
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        if k == 0:
            return len(set([i for i in nums if nums.count(i)>=2]))
        cl = [i+k for i in nums]
        return len(set(cl)&set(nums))
            
```
