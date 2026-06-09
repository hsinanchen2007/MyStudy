### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) > len(set(nums))
```