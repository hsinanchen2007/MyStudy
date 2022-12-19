### 解题思路
nums_ = nums[:]这里好像花费了O(n)的空间，是不是跑题了？

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums_ = nums[:]
        for num in nums_:
            if val == num:
                nums.remove(num)
        return len(nums)
```