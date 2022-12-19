### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return(self.divid_and_conquer(nums, 0, len(nums)-1))
    
    def divid_and_conquer(self, nums, low, high):
        if low == high:
            return nums[low]
        mid = (low + high)//2
        max_sum_left = self.divid_and_conquer(nums,low,mid)
        max_sum_right = self.divid_and_conquer(nums,mid+1,high)
        cross_suffix = 0
        sum = 0
        for i in range(mid-1,low-1,-1):
            sum += nums[i]
            cross_suffix = max(sum, cross_suffix)
        cross_prefix = 0
        sum = 0
        for i in range(mid+1,high+1):
            sum += nums[i]
            cross_prefix = max(sum, cross_prefix)
        cross_sum_max = cross_prefix + cross_suffix + nums[mid]
        return max(max_sum_left,cross_sum_max,max_sum_right)

```