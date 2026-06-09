### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        r, p = '', 0
        d = len(b) - len(a)
        a = '0' * d + a
        b = '0' * -d + b
        for i, j in zip(a[::-1], b[::-1]):
            s = int(i) + int(j) + p
            p, d =divmod(s,2)
            r = str(d) + r
            #r = str(s % 2) + r
            #p = s // 2
        return '1' + r if p else r

```