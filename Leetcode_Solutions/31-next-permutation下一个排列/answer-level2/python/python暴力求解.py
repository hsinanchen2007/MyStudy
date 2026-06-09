```
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        index=None
        length=len(nums)
        for i in range(length-2,-1,-1):
          if nums[i]<nums[i+1]:
            index=i
            break
        if index==None:
          nums.sort()
        else:
          #交换
          for i in range(length-1,-1,-1):
            if nums[i]>nums[index]:
               nums[index],nums[i]=nums[i],nums[index]
               break
          #再排序
          #nums[1+index:]=nums[1+index:][::-1]
          nums[1+index:]=nums[-1:index:-1]
```