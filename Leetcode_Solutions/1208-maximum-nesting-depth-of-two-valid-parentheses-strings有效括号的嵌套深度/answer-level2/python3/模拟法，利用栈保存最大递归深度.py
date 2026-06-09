### 解题思路

模拟法，先找到所有的最大递归深度，然后再模拟

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        s = []
        tmp_len = []
        max_len = float("-inf")
        if len(seq) == 0:
            return []
        max_depth = 0
        # 统计所有的递归深度中的最大值
        for char in seq:
            if char == ')':
                s.pop()
                if len(s) == 0:
                    tmp_len.append(max_depth)
                    max_len = max(max_len, max_depth)
                    max_depth = 0
            else:
                s.append(char)
                max_depth = max(max_depth, len(s))
        target = max_len // 2 + 1
        s = []
        res = []
        # 模拟，如果栈的深度超过了限制，就标记为1，否则标记为0
        for char in seq:
            if char == "(":
                s.append(char)
                if len(s) >= target:
                    res.append(1)
                else:
                    res.append(0)
            else:
                if len(s) >= target:
                    res.append(1)
                else:
                    res.append(0)
                s.pop()
        return res
```