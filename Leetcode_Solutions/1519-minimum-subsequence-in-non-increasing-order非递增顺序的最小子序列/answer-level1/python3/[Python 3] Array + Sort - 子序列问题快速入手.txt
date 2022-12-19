返回子序列而不是子串(子数组), 因此对nums递减排序, 然后自左向右累加nums[i]并存nums[i]至结果数组, 直到累加元素和 > 未累加元素和时, 跳出循环直接返回结果数组. 此时结果数组必然是最短且元素和最大的子序列。
时间复杂度O(nlogn), 空间复杂度O(n)。
```
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        curSum, total = 0, sum(nums)
        res = []
        nums = sorted(nums, reverse=True)
        for i in range(len(nums)):
            curSum += nums[i]
            res.append(nums[i])
            if curSum > total - curSum:
                break
        return res
        
```
