class Solution:
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        count = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                #求零的个数
                count += 1
            else:
                #当遇到非零数时,此时count存储的是此数之前的非零数的个数
                #那么这个非零数正确的位置应该为i-count
                nums[i-count] ,nums[i] = nums[i],nums[i-count]
