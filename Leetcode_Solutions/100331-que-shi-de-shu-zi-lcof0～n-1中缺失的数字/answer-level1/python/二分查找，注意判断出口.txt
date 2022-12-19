class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 二分法找到要插入的下标，就是结果
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            # 如果值等于下标，则左区间没缺失，寻找右区间[mid+1, right]
            if nums[mid] == mid:
                left = mid + 1
            else:
                right = mid

        # 列表只有一个元素时，上述循环没执行，要判断
        if nums[left] == left:
            return left + 1

        return left