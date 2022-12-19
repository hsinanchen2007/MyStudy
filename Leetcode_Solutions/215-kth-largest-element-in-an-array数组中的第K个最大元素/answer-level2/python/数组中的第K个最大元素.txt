```
class Solution(object):
    def _partition(self, nums, l, r):
        j = l
        for i in range(l + 1, r + 1):
            if nums[i] > nums[l]:
                j += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[l], nums[j] = nums[j], nums[l]
        return j

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        l, r, k = 0, len(nums) - 1, k - 1
        while 1:
            p = self._partition(nums, l, r)

            if k == p:
                return nums[p]
            elif k < p:
                r = p - 1
            else:
                l = p + 1
```