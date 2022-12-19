### 解题思路
遇上**排列/组合/子集**，立即推回溯+剪枝。

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(nums):
            res.append(tmp.copy())
            for i in range(len(nums)):
                tmp.append(nums[i])
                backtrack(nums[i+1:])
                tmp.pop()
        res = []
        tmp = []
        backtrack(nums)
        return res
```