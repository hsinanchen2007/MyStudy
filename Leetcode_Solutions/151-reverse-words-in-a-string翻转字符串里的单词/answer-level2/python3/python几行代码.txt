### 解题思路
python大法

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip().split()
        s.reverse()
        return ' '.join(s)
```
