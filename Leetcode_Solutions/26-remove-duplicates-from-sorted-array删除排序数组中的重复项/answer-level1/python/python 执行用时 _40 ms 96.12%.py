```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nlist = list(set(nums))
        nlist.sort()
        nums.clear()
        for data in nlist:
            nums.append(data)
        return len(nums)
```
