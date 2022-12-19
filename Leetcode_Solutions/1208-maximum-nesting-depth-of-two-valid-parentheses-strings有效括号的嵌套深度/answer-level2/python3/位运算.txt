### 解题思路
代码自注释

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        return [i & 1 ^ ord(c) - 40 for i, c in enumerate(seq)]
```