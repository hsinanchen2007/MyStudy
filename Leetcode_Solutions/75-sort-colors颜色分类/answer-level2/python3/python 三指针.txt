官方给的参考答案，跑不过官方给的测试样例，于是改了改，第一次编辑题解，哈哈有点开心

描述：python 三指针
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0 = curr = 0
        p2 = len(nums) - 1

        while curr <= p2:
            if nums[p0] == 0:
                p0 += 1
            if p0 < curr and nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
            if nums[curr] == 2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1
            else:
                curr += 1