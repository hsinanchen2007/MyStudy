### 解题思路
找到每个位置的最大数，遍历每个数字

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_num = nums[0]
        for i in range(1,len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
            max_num = max(max_num,nums[i])
        return max_num
```