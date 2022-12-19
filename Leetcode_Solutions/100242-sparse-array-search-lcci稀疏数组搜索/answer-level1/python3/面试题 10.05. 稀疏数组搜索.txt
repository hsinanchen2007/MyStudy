### 解题思路

列表解析

### 代码

```python []
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        return next((i for i, w in enumerate(words) if w == s), -1)
```