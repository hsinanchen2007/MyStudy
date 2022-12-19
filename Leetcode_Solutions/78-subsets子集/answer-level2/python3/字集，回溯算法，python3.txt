### 解题思路
回溯

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(L, temp):
            res.append(temp)
            for i in range(len(L)):
                backtrack(L[i+1:], temp+[L[i]])
        res = []
        backtrack(nums, [])
        return res
```