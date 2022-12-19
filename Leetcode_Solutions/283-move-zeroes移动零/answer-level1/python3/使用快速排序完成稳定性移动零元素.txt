本题以0元素为移动元素，要求其它元素位置相对不变，因此可以看成用0元素作为分界的快排，不同于快排的大于某元素的放一边，小于的放另一边，本题条件为是零的放一边，非零的放另一边
python代码实现：

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len_n = len(nums)
        p_0 = -1
        for i in range(len_n):
            if nums[i] != 0:
                temp = nums[p_0+1]
                nums[p_0+1] = nums[i]
                nums[i] = temp
                p_0 = p_0 + 1
            