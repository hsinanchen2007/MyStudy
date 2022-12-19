### 解题思路
使用 itertools 工具

### 代码

```python
import itertools
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return [list(i) for i in itertools.permutations(nums)]
```