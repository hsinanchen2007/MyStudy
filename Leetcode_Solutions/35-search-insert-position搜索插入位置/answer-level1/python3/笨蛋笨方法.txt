### 解题思路
数字直接拿来作比较，也不用二分法啦，记得循环的话要比较一下最后一位。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        ss = len(nums)
        for i in range(ss):
            if target == nums[i]:
                return i
            if target < nums[i]:
                return i
            if target > nums[-1]:
                return ss
```