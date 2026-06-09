### 解题思路
使用栈来维护记录下标

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = list()
        d = 0
        for s in seq:
            if s == '(':
                d += 1
                ans.append(d % 2)
            if s == ')':
                ans.append(d % 2)
                d -= 1
        return ans
```