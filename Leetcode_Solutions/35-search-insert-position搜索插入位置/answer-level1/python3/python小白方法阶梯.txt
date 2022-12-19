class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            nums.append(target)
            nums.sort(reverse=False)
            return nums.index(target)
解题思路十分小白

执行用时 :
52 ms, 在所有 Python3 提交中击败了95.72%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了99.54%的用户