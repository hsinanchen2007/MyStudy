```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k = 0
        len_nums = len(nums)
        
        if val not in nums:
            return len_nums
        
        for i in range(len_nums):
            if i == len_nums - 1 - k:
                break
            if nums[i] == val:
                while nums[len_nums - 1 - k] == val:
                    if len_nums - 1 - k == i + 1 :
                        return i
                    k+=1
                nums[i], nums[len_nums - 1 - k] = nums[len_nums - 1 - k], nums[i]


        return nums.index(val)
```

把val移到末尾再求index就行了。
