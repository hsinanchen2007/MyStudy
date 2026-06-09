class Solution:

    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        1. 新建一个数组，依次放入；
        2. 两层for
        3. 双指针（快慢指针）
        """
        # 3. 快慢指针
        j = 0  # 标记新索引的位置
        for i in range(len(nums)):
            if nums[i] != 0:  # 遇到非零元素，则交换当前值
                # 交换值
                nums[j], nums[i] = nums[i], nums[j]
                # 新索引加1
                j += 1

        return nums