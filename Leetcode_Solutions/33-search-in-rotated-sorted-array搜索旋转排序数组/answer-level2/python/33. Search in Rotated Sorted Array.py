```
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i, j = 0, len(nums) - 1
        if len(nums) == 1:
            return 0 if nums[0] == target else -1

        while (i <= j):
          if nums[i] == target:
              return i
          if nums[j] == target:
              return j
          i += 1
          j -= 1
        return -1
```
