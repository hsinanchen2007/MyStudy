```python []
class Solution:
    def strToInt(self, str: str) -> int:
        for i, c in enumerate(str):
            if '0' <= c <= '9' or c in '+-':
                res, t = '0', c == '-' and -1 or 1
                i += c in '+-'
                for c in str[i: ]:
                    if not '0' <= c <= '9':
                        break
                    res += c
                res = t * int(res)
                return min(2147483647, max(res, -2147483648))
            elif c == ' ':
                continue
            else:
                break
        return 0
```