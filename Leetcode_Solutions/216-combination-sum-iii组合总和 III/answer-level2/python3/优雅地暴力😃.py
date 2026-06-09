```python
# 1. 找出所有组合
# 2. 筛选符合条件的组合
# 3. 返回
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        all_nums = itertools.combinations([i for i in range(1, 10)], k)
        res = filter(lambda nums: sum(nums) == n, all_nums)
        return list(res)
```