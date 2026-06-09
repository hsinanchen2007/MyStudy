### 解题思路
若在则移除，不在便return

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums: nums.remove(val)
        return len(nums)
```