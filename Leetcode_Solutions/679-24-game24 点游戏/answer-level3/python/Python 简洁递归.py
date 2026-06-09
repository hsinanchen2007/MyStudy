```python
from operator import mul, add, truediv, sub
from itertools import permutations
from functools import lru_cache


class Solution:

    def judgePoint24(self, nums: List[int]) -> bool:
        @lru_cache(None)
        def dfs(nums):
            if len(nums) == 1:
                return abs(nums[0]-24) < 1e-5
            (a, b), nums = nums[:2], nums[2:]
            ops = (mul, add, sub) + (b != 0) * (truediv,)
            return any(dfs(nums[:i] + (op(a, b),) + nums[i:])
                       for op in ops for i in range(len(nums)+1))

        return any(dfs(permu) for permu in permutations(nums, 4))

```