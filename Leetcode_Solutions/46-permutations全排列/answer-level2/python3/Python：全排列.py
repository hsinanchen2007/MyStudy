### 解题思路
Python的迭代器确实好用

### 代码

```python3
import itertools
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums,len(nums)))
```