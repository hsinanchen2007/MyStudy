### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums: return [[]]
        ans = []
        length = len(nums)
        for i in range(length + 1):
            for j in itertools.combinations(nums, i):
                ans.append(list(j))
        return ans
```