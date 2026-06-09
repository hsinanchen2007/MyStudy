### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) <= len(set(nums)): return False
        else: return True
        
```