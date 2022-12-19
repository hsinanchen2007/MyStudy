### 解题思路


### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        return list(Counter(nums).most_common(1)[0])[0]
```