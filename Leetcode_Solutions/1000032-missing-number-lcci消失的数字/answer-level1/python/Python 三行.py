
取最大元素构建新列表，取两个列表的差集。

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        new = [i for i in range(len(nums)+1)]
        return list(set(new).difference(set(nums)))[0]
```
