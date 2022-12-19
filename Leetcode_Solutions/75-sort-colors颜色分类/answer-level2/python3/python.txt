先遍历一遍0，遇到第一个0，将0放在nums[0],第二个0，放在nums[1]，以此类推
再遍历1，将1继续放在后面
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        for i in range(j, len(nums)):
            if nums[i] == 1:
                nums[j], nums[i] = nums[i], nums[j]
                j += 1