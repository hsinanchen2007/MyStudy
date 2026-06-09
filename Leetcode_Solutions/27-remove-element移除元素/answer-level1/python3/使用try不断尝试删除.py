### 解题思路
删到不能删除为止

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while True:
            try:
                nums.remove(val)
            except:
                return len(nums)
```
