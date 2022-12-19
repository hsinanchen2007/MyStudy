### 解题思路
此处撰写解题思路
简单的想法就是判断nums这个列表中还有val这个值吗？
有就remove 1 次，直至没有为止
### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
        return len(nums)
```