class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
                continue                  #删除后要重新检验该处的值
            i += 1                        #不删除则继续下一个索引值
        return len(nums)