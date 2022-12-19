### 解题思路
大小写字母ASCII值差32，利用ord()函数即可

### 代码

```python3
class Solution:
    def toLowerCase(self, str: str) -> str:
        result = ""
        for s in str:
            if s >= 'A' and s <= 'Z':
                s = chr(ord(s) + 32)
            else:
                pass
            result += s
        return result



```