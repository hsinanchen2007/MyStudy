class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        d = len(nums)
        if d ==k or k == 0:
            return nums
        elif d < k:
            nums.extend(nums[-(k-d):])
            nums.extend(nums[:-2 * (k-d)])
            del nums[:d]
            return nums

        else:
            nums.extend(nums[-k:])
            nums.extend(nums[:-2*k])
            del nums[:d]
            return nums