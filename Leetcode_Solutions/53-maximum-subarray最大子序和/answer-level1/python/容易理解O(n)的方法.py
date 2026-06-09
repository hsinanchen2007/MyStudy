```py
class Solution(object):
    def maxSubArray(self, nums):
        n = len(nums)

        tmp = nums[0] # 局部最优解
        maxV = tmp    # 整体最优解

        for i in range(1,n):
            if tmp + nums[i] > nums[i]:
                tmp += nums[i]
            else:
                tmp = nums[i]

            if tmp > maxV:
                maxV = tmp

        return maxV
```
