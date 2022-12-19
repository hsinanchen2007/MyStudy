### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        pre, cur = 0, 0

        for num in nums:
            pre, cur = cur, max(num + pre, cur)
        return cur
```