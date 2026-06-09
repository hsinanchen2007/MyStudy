### 解题思路
python内置的切片语法，一行代码解决

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]
```