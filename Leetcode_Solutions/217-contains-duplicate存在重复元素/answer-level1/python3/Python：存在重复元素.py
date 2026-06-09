### 解题思路
统计元素数量

### 代码

```python3
import collections
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        for i,j in collections.Counter(nums).items():
            if j>1:return True 
        return False 
```