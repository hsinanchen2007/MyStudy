### 解题思路
此处撰写解题思路
贪心算法
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        m = len(nums)
        maxsub = -1e10
        maxsum = -1e10
        for i in range(m):
            maxsub = max(maxsub+nums[i],nums[i])
            if maxsub > maxsum:
                maxsum = maxsub
        return maxsum


```