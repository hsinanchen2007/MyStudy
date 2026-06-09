### 解题思路
一行解决

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.strip().split()[::-1])
```