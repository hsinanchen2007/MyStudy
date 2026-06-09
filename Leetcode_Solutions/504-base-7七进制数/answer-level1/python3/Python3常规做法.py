```
def convertToBase7(self, num: int) -> str:
    if not num: return '0'
    n = abs(num)
    s = ''
    while n > 0:
        q, r = divmod(n, 7)
        s = str(r) + s
        n = q
    return s if num > 0 else '-' + s
```
