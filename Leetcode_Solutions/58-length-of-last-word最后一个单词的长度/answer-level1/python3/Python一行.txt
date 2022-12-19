### 解题思路
没啥好说的 Python大法好

### 代码

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip().split()[-1]) if len(s.strip()) > 0 else 0
```