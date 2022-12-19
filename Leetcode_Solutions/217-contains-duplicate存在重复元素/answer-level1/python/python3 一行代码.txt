### 解题思路
若存在重复值，set的长度将小于list的长度。

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
```