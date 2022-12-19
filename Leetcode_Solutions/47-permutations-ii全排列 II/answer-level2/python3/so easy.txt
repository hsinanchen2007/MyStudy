### 解题思路
此处撰写解题思路

### 代码

```python3
import itertools
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return list(set(itertools.permutations(nums)))

```