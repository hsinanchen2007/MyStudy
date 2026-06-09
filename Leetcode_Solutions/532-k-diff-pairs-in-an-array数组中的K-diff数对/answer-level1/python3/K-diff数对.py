参照两数之和的解法，结合大神的k == 0 的解法特例
```
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        count = 0
        n = len(nums)
        hash = {}
        for ind,num in enumerate(nums):
            hash[num] = ind
        if k > 0:
            for i,num in enumerate(nums):
                j = hash.get(nums[i] + k)
                if j is not None and i != j and nums[i] != nums[i+1]:
                    count += 1
            return count
        elif k == 0:
            c = collections.Counter(nums)
            return len([i for i in c if c[i] > 1])
        else:
            return 0

```
