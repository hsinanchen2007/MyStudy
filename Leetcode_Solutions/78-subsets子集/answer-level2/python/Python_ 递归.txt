### 解题思路
简单的递归。此题用memoization并无帮助。

### 代码

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0: return [[]]
        if len(nums) == 1: return [[], nums]
        tmp = self.subsets(nums[:-1])
        return tmp + [sub + [nums[-1]] for sub in tmp]
                
```