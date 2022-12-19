### 解题思路
判断集合和列表长度是否相等

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return not len(set(nums))==len(nums)
```