14 行 python
```python
class Solution:
    def decodeString(self, s: str) -> str:
        stack, a, n = [['', 1, '']], '', ''
        for c in s:
            if c.isalpha():
                a += c
            elif c.isdigit():
                n += c
            elif c == '[':
                stack.append([a, int(n), ''])
                a = n = ''
            else:
                p, t, b = stack.pop()
                stack[-1][-1] += p + t * (b + a)
                a = ''
        return stack.pop()[-1] + a
```
- 用 stack 记录（[]之前的字母，翻倍次数，翻倍内容）