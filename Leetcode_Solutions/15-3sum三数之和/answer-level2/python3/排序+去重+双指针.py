一、排序
二、循环
中心思想
如果当前数和前一个数相同，去重，继续一下个；如果当前树大于零，则跳出循环（后面的数都大于零，不用再计算）。
循环到当前数和之后的两个数（最靠近当前L和最远离当前R）相加，如果等于零，则添加，继续循环；
如果小于零，L右移一位（和变大）；如果大于零，R左移一位（和变小）。
考虑去重。

1、如果 nums[i] >0 则后面的都大于零，三数之后大于零直接跳出
   如果nums[i] == nums[i-1]，则循环下一个，去重，避免重复计算
2、设置L 、R;  L= i+1 R = len(nums) - 1 
3、当 L < R时循环
   sum = nums[L]+nums[R]+ nums[i]
   3.1 如果 sum =0, 添加到结果
        去重 
        如果L+1和L重复，L右移一位，直到不重复
        如果R-1和R重复，R左移一位，直到不重复 
        L右移一位
        R左移一位   
  3.2 如果sum大于零 R左移一位
  3.3 如果sum 小于零 L 右移一位

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums_len = len(nums)
        if nums_len < 3:
            return res
        nums.sort()
        for i in range(nums_len):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = nums_len - 1
            while left < right:
                num_sum = nums[i] + nums[left] + nums[right]
                if num_sum == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left = left + 1
                    while left < right and nums[right-1] == nums[right]:
                        right = right-1
                    right = right - 1
                    left = left + 1
                elif num_sum > 0:
                    while left < right and nums[right-1] == nums[right]:
                        right = right - 1
                    right = right - 1
                else:
                    while left < right and nums[left] == nums[left + 1]:
                        left = left + 1
                    left = left + 1
        return res