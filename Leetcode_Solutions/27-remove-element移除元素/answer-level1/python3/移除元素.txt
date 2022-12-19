双指针，begin指针判断是否为要删除的值，如果不是，就把nums[begin]复制到num[end],并把end自增，如果nums[begin]是删除的val，跳过不复制。

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        end = 0
        begin = 0
        length = len(nums)
        if length == 0:
            return 0
        for begin in range(length):
            if nums[begin] == val:
                continue
            else:
                nums[end] = nums[begin]
                end += 1
        return end