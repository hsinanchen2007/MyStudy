### 解题思路
字符串去头尾空格，列表化
倒序入串

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        L = list(s.strip().split())
        return ' '.join(L[::-1])
```