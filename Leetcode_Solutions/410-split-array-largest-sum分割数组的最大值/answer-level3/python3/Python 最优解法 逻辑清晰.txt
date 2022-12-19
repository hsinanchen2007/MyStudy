```
class Solution(object):
    def splitArray(self, nums, m):
        # binary search for min_max
        left, right = sum(nums) / m, sum(nums)
        while left <= right:
            mid = right - ((right - left) >> 1)
            if self.valid_max(nums, m, mid) and (not self.valid_max(nums, m, mid-1)):
                return mid
            else:
                if not self.valid_max(nums, m, mid):
                   left = mid + 1
                else:
                   right = mid - 1

        return right 
    
    def valid_max(self, nums, k, max):
        n = len(nums)
        div = 1
        sum = nums[0]
        for i in range(1, n):
            if sum > max:
                return False
            if sum + nums[i] > max:
                div += 1
                sum = nums[i]
            else:
                sum += nums[i]
        # note that we have to ensure sum <= max
        return (sum <= max) and (div <= k)
  
```
