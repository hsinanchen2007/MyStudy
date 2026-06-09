### 解题思路
一个while循环加一个remove，直到数组不含目标值，返回移除元素后的长度

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
        return len(nums)
```