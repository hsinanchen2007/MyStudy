### 解题思路
类似组合总和的解法

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        
        def helper(temp, i):
            if i > n:
                return
            res.append(temp)
            for j in range(i, n):
                helper(temp+nums[j:j+1], j+1)
        
        helper([], 0)
        return res
        
        
```