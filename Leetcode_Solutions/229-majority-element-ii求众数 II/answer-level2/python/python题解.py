```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        m = collections.Counter(nums)
        for key, val in m.items():
            if val > (len(nums) // 3):
                result.append(key)
        return result
```
