class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if val != nums[j]:
                nums[i]=nums[j]
                i+=1
        return i

113/113 cases passed (28 ms)
Your runtime beats 96.9 % of python3 submissions
Your memory usage beats 5.08 % of python3 submissions (13.6 MB)