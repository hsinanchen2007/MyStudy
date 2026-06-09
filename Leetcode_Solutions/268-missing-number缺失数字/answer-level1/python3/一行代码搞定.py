
```


class Solution:
    def missingNumber(self, nums):
        return list(set(nums)^set(list(range(len(nums)+1))))[0]
