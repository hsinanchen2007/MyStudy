### 解题思路
动态规划的核心是缩小问题规模，将大问题拆解为小问题。思考路径如下 
1. 计算出每个位置上的最大值，就是说必须偷该房屋的情况下最大值是多少。
2. 如果必须包含该位置的数字，那么最大值就是该位置的数字 + MAX(max_frofit(n-2), max_frofit(n-3))。
3. 找出所有位置最大值中，最大的那个数字。

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        max_robbed = 0
        robbed_set = dict()
        for k in range(0,len(nums)):
            if not robbed_set.get(k-2):
                robbed_set[k] = nums[k]
                max_robbed = max(max_robbed,robbed_set[k])
            else:
                robbed_set[k] = max(nums[k] + robbed_set[k-2],nums[k] + robbed_set.get(k-3,0))
                max_robbed = max(max_robbed,robbed_set[k])
        
        return max_robbed
```