输入是个数组，就用数组自带的方法去处理：
nums.count(nums[i])：获取相同元素的个数；
nums.remove(nums[i])：删除指定元素的第一个；

通过count，判断如果个数大于1，就调用remove方法，去掉一个


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lenth = len(nums)
        i = 0
        while i < lenth:
            if nums.count(nums[i]) > 1:
                nums.remove(nums[i])
                lenth = len(nums)
            else:
                i = i + 1
        return len(nums)