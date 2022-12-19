### 解题思路
insert()即可

### 代码

```python3
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums.insert(index[i], nums.pop(i))
        return nums
```