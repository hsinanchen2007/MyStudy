### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m = min(nums)
        s = 0
        for i in nums:
            s += i - m
        return s
```