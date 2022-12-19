### 解题思路
1. 内置函数，感觉像作弊一样。。。
2. ASCII码来判断大小写，大写和小写相差32

### 代码

```python3
class Solution:
    def toLowerCase(self, str: str) -> str:
        # return str.lower()

        if 'A' <= item <= 'Z':
            item = chr(ord(item) + 32)
        return item
```