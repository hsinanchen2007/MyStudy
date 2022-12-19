### 解题思路
如代码
### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        is_rise = True
        re = ''
        while s:
            set_s = set(s)
            if is_rise:
                re += ''.join(sorted(list(set_s)))
            else:
                re += ''.join(sorted(list(set_s), reverse = True))
            is_rise = not is_rise
            for l in set_s:
                s = s[:s.index(l)]+s[s.index(l) +1:]
        return re
```