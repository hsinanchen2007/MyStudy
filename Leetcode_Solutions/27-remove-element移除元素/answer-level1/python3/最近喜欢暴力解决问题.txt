### 解题思路
这应该很简单把

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        try:
            while True:
                nums.remove(val)
        except:
            return len(nums)
```