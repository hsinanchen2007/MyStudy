### 解题思路
小偷？着色？

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        a, b = 0, 0
        for i in nums:
            a,b = b,max(b,a+i)
        return b
```