### 解题思路
要简单成这样才能一次通过了嘛:3

### 代码

```python3
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] == i:
                return i
        
        return -1
```