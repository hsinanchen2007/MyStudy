# 解法一:
使用正向查找时, 删除元素会导致后面的索引与期望的不一致,
反向查找, 删除元素后, 不影响后面的索引
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i in range(0, len(nums))[::-1]:
            if nums[i] == val:
                del nums[i]
        return len(nums)


# 解法二:
使用异常跳出循环
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        try:
            while True:
                nums.remove(val)
        except ValueError as e:
            pass
        return len(nums)