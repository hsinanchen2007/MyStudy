### 解题思路
跟着套路写就完事了

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res_all = []
        def dfs(begin, res):
            if res not in res_all:
                res_all.append(res[:])
            for i in range(begin, len(nums)):
                res.append(nums[i])
                dfs(i + 1, res)
                res.pop()
        dfs(0, [])
        return res_all

    
```