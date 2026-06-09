### 解题思路
set集合去重比较长度即可。还可以遍历计数

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
```