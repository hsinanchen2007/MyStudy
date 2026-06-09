### 解题思路
pos为此时最大正值，neg为此时最小负值。
遇到小于0就换，大于0就继续乘，其中nums[i]是用来更新变号后大小。

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        pos, neg, res = 1, 1, -float('inf')
        for i in range(len(nums)):
            pos, neg = max(neg*nums[i], pos*nums[i], nums[i]), min(pos*nums[i], neg*nums[i], nums[i])
            res = max(res, pos)
        return res



```