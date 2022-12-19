### 解题思路
和全排1相比，就是去重，能想到三种：
set
groupby
filterfalse

### 代码

```python3
import itertools
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return list(set(itertools.permutations(nums,len(nums))))
```