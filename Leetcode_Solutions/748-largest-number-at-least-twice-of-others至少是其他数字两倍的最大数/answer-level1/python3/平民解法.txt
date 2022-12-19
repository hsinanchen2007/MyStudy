复制一个列表，删除最大值，对比新旧的最大值
```python []
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        a = max(nums)
        l = nums[:]
        l.pop(nums.index(max(l)))
        if l == []:
            return 0
        elif a >= max(l)*2:
            return nums.index(a)
        else:
            return -1
```

