class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        tmp1 = [i for i in range(1,len(nums)+2)]
        tmp2 = [i for i in range(-1,-len(nums)-2,-1)]
        fin = set(tmp1)-(set(nums)-(set(nums)&set(tmp2)))
        return min(fin)