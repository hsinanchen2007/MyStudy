### 解题思路
双指针，直接替换列表中的值，判断值是否等于val

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1
        return j
```