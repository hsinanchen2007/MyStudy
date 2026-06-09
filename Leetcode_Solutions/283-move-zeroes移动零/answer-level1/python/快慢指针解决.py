```
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        slow = 0
        for fast in xrange(0,length):#要处理到最后一个数字，例如 0 0 0 1 这样的场景
            if nums[fast] != 0:
                nums[slow] = nums[fast]
                if slow != fast:#很重要，处理非0开头的序列和连续非零数字的场景
                    nums[fast] = 0
                slow +=1
                
```
