```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        #执行用时 :56 ms, 在所有 python3 提交中击败了98.50%的用户
        #内存消耗 :13.4 MB, 在所有 python3 提交中击败了99.33%的用户
        #暴力破解
        i =0
        if nums[0]>target:
            return 0
        while i < len(nums):
            if nums[i]==target:
                return i
            elif nums[i]<target and i+1 < len(nums) and nums[i+1]>target:
                return i+1
            elif i+1 == len(nums) and nums[i]<target:
                return i+1
            else:
                i+=1
        #二分法
        #执行用时 :60 ms, 在所有 python3 提交中击败了94.26%的用户
        #内存消耗 :13.4 MB, 在所有 python3 提交中击败了99.48%的用户
        left = 0 
        right = len(nums)-1
        if target in nums:
            return nums.index(target)
        while left<=right:
            mid = (left+right)>>1
            if target>nums[mid]:
                left = mid+1
            else:
                right = mid-1
        return left




```
