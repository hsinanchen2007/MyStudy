### 解题思路
位运算，简便快捷，强强强

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a=0
        for num in nums:
            a^=num
        return a
```