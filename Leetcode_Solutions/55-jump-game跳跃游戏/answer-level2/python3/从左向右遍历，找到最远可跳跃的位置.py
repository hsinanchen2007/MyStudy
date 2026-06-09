思路：
    思想很简单，从左向右遍历，找到最远可跳跃的位置。如果遍历的指针位置小于最远可跳跃位置，则可以继续前进；但是如果遍历指针的位置就是当前最远可跳跃的位置，则不能继续前进，意味着False。

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # 可跳跃最远位置
        maxP = nums[0] + 0

        for i in range(len(nums)):
            if maxP >= len(nums)-1:
                return True
            
            if maxP < nums[i] + i:
                maxP = nums[i] + i
            
            if maxP == i :
                return False


 

