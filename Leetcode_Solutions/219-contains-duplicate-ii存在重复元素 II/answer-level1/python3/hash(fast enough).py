```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic = {}
        for index, var in enumerate(nums):
            if dic.get(var) is not None:
                if index - dic[var] <= k:
                    return True
            dic[var] = index
        return False
            
```
