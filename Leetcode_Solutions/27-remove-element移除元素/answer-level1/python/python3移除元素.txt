### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
        return len(nums)
```