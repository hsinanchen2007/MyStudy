### 解题思路
insert
### 代码

```python3
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for  i in range(len(nums)):
            target.insert(int(index[i]), int(nums[i]))
        return target
```