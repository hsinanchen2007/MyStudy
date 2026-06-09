思路：遍历整个数组，更新跳数，碰到比当前跳数大的数就更新跳数，如果跳数为0且不为最后一个数，则不能忘往前跳了，返回False，否则返回True

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        count = 0 # 跳数
        for i in range(len(nums)):
            count -= 1
            if nums[i] > count:
                count = nums[i] # 如果当前数大于跳数，跳数更新为当前数
            if count == 0 and i != len(nums)-1: # 如果目前跳数为0而且不是最后一个数，则返回False
                return False
        return True
            