class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        p = 0
        q = 0
        while q < n-1:
            q += 1
            if nums[p] != nums[q]:
                p += 1
                nums[p] = nums[q]
        return p+1