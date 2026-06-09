向右旋转k次即整体左移len(nums)-k%len(nums)次，每次左移都可以看做将列表首元素加入尾部，再删除首元素

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        for i in range(len(nums)-k%len(nums)):
            nums.append(nums[0])
            nums.pop(0)