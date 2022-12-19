### 解题思路

### 代码

```python3
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        return words.index(s) if s in words else -1
```