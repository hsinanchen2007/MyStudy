### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        return sorted(s1)==sorted(s2)
```