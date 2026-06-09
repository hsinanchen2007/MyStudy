```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash = {}
        for ind,num in enumerate(nums):
            if num not in hash:
                hash[num] = 1
            else:
                hash[num] += 1
        return list(hash.keys())[list(hash.values()).index(1)]
```
