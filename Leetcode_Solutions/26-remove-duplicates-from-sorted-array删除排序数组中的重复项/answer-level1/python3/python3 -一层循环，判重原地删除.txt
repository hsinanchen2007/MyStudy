class Solution:

    def removeDuplicates(self, nums: List[int]) -> int:
        # 1. 利用排序的数组
        i = 0
        # 遍历数组
        while i < len(nums):
            # 已排序的数组，那么重复的数据就在后面
            if i + 1 < len(nums) and nums[i] == nums[i + 1]:
                # 如果当前值与后面的值重复就删除当前值
                del nums[i]
            else:
                # 否则往后移动
                i += 1
        return len(nums)  # 返回已删除重复项的数组的长度

