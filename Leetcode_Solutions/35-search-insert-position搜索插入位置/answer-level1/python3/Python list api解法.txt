class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        if target not in nums:
            nums.append(target)
            nums.sort()

        return nums.index(target)

如果不在其中就插入进去
最后取出其位置

大神们干嘛搞的这么复杂···
