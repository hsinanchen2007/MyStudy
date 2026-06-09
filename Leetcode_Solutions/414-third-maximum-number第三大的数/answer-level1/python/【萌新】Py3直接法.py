### 解题思路
暂时只想到pop弹出。。。

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums=list(set(nums))
        if len(nums)<3:
            return max(nums)
        elif len(nums)>=3:
            nums.pop(nums.index(max(nums)))
            nums.pop(nums.index(max(nums)))
        return max(nums)
```