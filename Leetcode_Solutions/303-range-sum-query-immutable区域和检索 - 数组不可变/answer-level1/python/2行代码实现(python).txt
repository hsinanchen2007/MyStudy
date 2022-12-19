```
class NumArray(object):
    def __init__(self, nums):
        self._sum = [sum(nums[:i]) for i in range(len(nums)+1)]
    def sumRange(self, i, j):
        return self._sum[j+1] - self._sum[i]
```
