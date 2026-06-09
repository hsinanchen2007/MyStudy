### 解题思路
py3很方便

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
```