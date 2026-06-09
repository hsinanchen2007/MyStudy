### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_sum = float('-inf')
        curr_sum = 0
        for i in range(len(nums)):
            curr_sum += nums[i]
            # 记录历史出现过的最大和
            if curr_sum > max_sum:
                max_sum = curr_sum
            # 如果当前的和小于0，那么它对于总和只有负面影响，所以归零
            if curr_sum < 0:
                curr_sum = 0
        return max_sum
            
            

```