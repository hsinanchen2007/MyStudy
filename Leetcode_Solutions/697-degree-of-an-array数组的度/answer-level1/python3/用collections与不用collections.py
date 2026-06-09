用collections要经过4-5次O(n)，按官方题解的方法要快的多

```
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        # 1. use collections
        # counter = collections.Counter(nums)  # O(n)
        # max_v = max(counter.values()) # O(n)
        # nums_ = nums[::-1]  # O(n)
        # value = [k for k, v in counter.items() if v == max_v]  # O(n)
        # return min([len(nums) - nums_.index(v) - nums.index(v) for v in value]) # O(n)
        
        # 2. O(n) twice
        left, right, count = {}, {}, {}
        for i, k in enumerate(nums):
            if k not in left: left[k] = i
            right[k] = i
            count[k] = count.get(k, 0) + 1
        ans = len(nums)
        degree = max(count.values())
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)
        return ans
            
```