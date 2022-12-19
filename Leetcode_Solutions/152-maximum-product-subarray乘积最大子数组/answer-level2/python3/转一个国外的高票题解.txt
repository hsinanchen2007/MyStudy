虽然是个中等题，但是感觉特别难想，特别是0和负数的处理，最后只能看答案了。
转一个看到的国外高票Python题解
```python3
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxProduct(self, nums):
        i = 0
        currentMax, currentMin, ans = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            n = nums[i]
            tmp = currentMax
            currentMax = max(n, n*currentMax, n*currentMin)
            currentMin = min(n, n*tmp, n*currentMin)
            ans = max(ans, currentMax)
        return ans
```