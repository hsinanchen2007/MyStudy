### 解题思路
库函数一行

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```