```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        if not nums:
            return None
        set1 = set(nums)
        set2=set(range(1,len(nums)+1))
        return list(set2-set1)
```
