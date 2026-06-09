![只出现一个数字mem.PNG](https://pic.leetcode-cn.com/1c3825e893e184f851e7d556a985a6fd2630d14413d0f90f3ca4fcda973e92d8-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97mem.PNG)
![只出现一个数字time.PNG](https://pic.leetcode-cn.com/88e6ccbfc00c91d292d12b769925680b02e3eea58203e5210865a30f22156ddd-%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97time.PNG)
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return nums[0]
        sorted_nums=sorted(nums)
        

        
        for i in range(1,len(sorted_nums)-1):
            if sorted_nums[i-1]!=sorted_nums[i] and sorted_nums[i+1]!=sorted_nums[i]:
                return sorted_nums[i]
        
        if sorted_nums[0]!=sorted_nums[1]:
            return sorted_nums[0]
        if sorted_nums[len(sorted_nums)-2]!=sorted_nums[len(sorted_nums)-1]:
            return sorted_nums[len(sorted_nums)-1]
```

