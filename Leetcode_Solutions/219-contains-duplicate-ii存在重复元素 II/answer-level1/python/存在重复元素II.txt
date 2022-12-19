```
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        num = {}
        for i in range(len(nums)):
            if nums[i] in num:
                dist = i - num[nums[i]]
                if dist <= k:
                    return True
                else :
                    num[nums[i]] = i
            else:
                num[nums[i]] = i
        return False
```