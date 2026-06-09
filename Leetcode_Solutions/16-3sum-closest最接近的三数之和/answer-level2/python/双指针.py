### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        nums = sorted(nums)
        l = 0
        
        r = len(nums) - 1
        diff = float('inf')
        res = None
        while l< r:
            mid=l+1
            r = len(nums)-1
            while mid < r:
                
                if l >= mid:
                    mid += 1

                if mid >= r:
                    mid -= 1
                if l >= mid or mid >= r:
                    break

                if abs(nums[l] + nums[mid] + nums[r] - target) < diff:
                    diff = abs(nums[l] + nums[mid] + nums[r] - target)
                    res = nums[l] + nums[mid] + nums[r]
                if nums[l] + nums[mid] + nums[r] - target > 0:
                    r -= 1
                elif nums[l] + nums[mid] + nums[r] - target < 0:
                    mid += 1
                else:
                    return res
            l += 1

        return res
```