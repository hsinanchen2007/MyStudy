### 解题思路
因为是连续子序列和，所以每次从当前数出发，考察到该位置的最大和，该位置的数要么参与了和，要么就是它本身，如果当前数 + 前一个数能使得当前数的处境更好，则相加，否则不作为

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:return 
        for i in range(1, len(nums)):
            if nums[i - 1] + nums[i] > nums[i]:
                nums[i] += nums[i - 1]
        return max(nums)

```