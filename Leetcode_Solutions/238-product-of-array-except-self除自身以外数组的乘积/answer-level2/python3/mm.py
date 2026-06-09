```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        res, l, r = [1] * n, 1, 1
        for i in range(n):
            res[i], l = res[i] * l, l * nums[i]
            res[n-i-1], r = res[n-i-1] * r, r * nums[n-i-1]
        return res


```
