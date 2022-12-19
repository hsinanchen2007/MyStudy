### 解题思路
1. 遍历数组，取累计最大值
2. 动态规划，f[k] = max(nums[k], f[k-1] + nums[k])

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # n = len(nums)
        # curr_sum = max_sum = nums[0]

        # for i in range(1, n):
        #     curr_sum = max(nums[i], curr_sum + nums[i])
        #     max_sum = max(max_sum, curr_sum)
            
        # return max_sum

        n = len(nums)
        max_sum = nums[0]

        for i in range(1,n):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
            max_sum = max(nums[i], max_sum) 
        return max_sum
```