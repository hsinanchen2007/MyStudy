class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        mid_index = len(nums) // 2
        mid_num = nums[mid_index]
        nums.remove(mid_num)
        temp = []
        for i in nums:
            if mid_num <= i:
                step = i - mid_num
                temp.append(step)
            else:
                step = mid_num - i
                temp.append(step)
        return sum(temp)