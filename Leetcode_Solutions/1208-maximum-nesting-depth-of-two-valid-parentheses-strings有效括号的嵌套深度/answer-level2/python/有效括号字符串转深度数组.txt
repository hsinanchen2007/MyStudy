### 解题思路
1. 深度最小的拆分方法是将括号字符串按照深度奇偶数拆分，这样高深度的括号字符串，深度降低了1 / 2
2. 如何得到每个括号的深度呢？我们认为出现一次 **(** 则深度加一，出现一次 **)** 深度减一，但是当出现 **)** 时，首先应该使用深度值，再做减一操作

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        depth = 0
        arr = []
        left = '('
        for ch in seq:
            if ch == left:
                depth += 1
                arr.append(depth & 1)
            else:
                arr.append(depth & 1)
                depth -= 1
        return arr
```