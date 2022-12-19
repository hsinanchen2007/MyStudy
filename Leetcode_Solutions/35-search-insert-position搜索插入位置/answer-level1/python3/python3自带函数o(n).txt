用自带函数写的一个容易理解的解法

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            array2 = nums
            array2.append(target)
            array2.sort()
            return array2.index(target)