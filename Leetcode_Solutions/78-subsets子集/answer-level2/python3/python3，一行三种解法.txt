### 解题思路
都是用组合，三种解法。


### 代码

```python3
from itertools import combinations
from functools import reduce
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # 方法1
        # ans = []
        # for i in range(len(nums) + 1):
        #     ans.extend(list(combinations(nums, i)))
        # return ans

        # 方法2
        # return sum([list(combinations(nums, i)) for i in range(len(nums) + 1)], [])
        
        # 方法3
        return reduce(operator.iconcat, [list(combinations(nums, i)) for i in range(len(nums) + 1)], [])



```