class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # 倒叙的方式，避免删除元素时对其之后的元素位置变化的干扰
        for i in range(len(nums))[::-1]:
            if nums[i] == val:
                del nums[i]
        return len(nums)