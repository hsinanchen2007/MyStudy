### 解题思路
可以一行，但没必要。


### 代码

```python3
from itertools import combinations
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for i in range(len(nums) + 1):
            ans.extend(list(combinations(nums, i)))
        return ans

        # return sum([list(combinations(nums, i)) for i in range(len(nums) + 1)], [])



```