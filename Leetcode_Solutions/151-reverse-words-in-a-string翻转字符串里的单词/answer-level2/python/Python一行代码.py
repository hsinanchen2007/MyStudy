### 解题思路

Python一行代码。。。

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.strip().split()[::-1])
```