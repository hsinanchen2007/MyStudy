# 依次比较前n个元素数组是否满足即可
class Solution:
    def minSubsequence(self, nums: list) -> list:
        if(len(nums)<2):
            return nums
        nums.sort(reverse=True)
        subList = [nums[0]]
        idx = 1
        while(sum(subList) <= sum(nums[idx:])):
            subList.append(nums[idx])
            idx += 1
        return subList