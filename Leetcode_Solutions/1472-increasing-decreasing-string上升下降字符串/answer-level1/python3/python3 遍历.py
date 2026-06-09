用了内置list.sort()函数来排序，应该算是一个作弊方法吧..

```python []
class Solution:
    def sortString(self, s: str) -> str:
        if not s: return ''

        s = list(s)
        res = []
        while s:
            c_list = list(set(s))
            c_list.sort(key=lambda c: ord(c))
            for i in c_list:
                res.append(i)
                s.remove(i)

            c_list = list(set(s))
            c_list.sort(key=lambda c: ord(c), reverse=True)
            for i in c_list:
                res.append(i)
                s.remove(i)
        return ''.join(res)
```
