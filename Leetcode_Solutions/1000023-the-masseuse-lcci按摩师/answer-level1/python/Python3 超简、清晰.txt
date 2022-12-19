### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        yes, no = 0, 0
        for num in nums:
            yes, no = num + no, max(yes, no)
        return max(yes, no)
```