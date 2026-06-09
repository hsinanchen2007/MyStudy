![捕获.PNG](https://pic.leetcode-cn.com/4507c6185265ae4071d4b08d13144fe2caa6caa7775417bee6c6fd5f5b8d461f-%E6%8D%95%E8%8E%B7.PNG)
只要保证数组中新长度范围内的元素无重复，不需要考虑数组中超出新长度后面的元素

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = 1
        while j < len(nums):
            if nums[i] != nums[j]:
                nums[i+1] = nums[j]
                i += 1
                j += 1
            else:
                j += 1
 
        return len(set(nums))