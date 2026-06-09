思路很简单：（1）把非零元素移动到列表前面，（2）列表后面的元素全部用0覆盖
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #数组判空
        if not nums:
            return 0
        #双指针法--滑动窗口
        front,rear=0,0
        while front!=len(nums):
            if nums[front]!=0:
                nums[rear]=nums[front]
                rear+=1
            front+=1
        nums[rear:]=[0 for i in range(len(nums[rear:]))]