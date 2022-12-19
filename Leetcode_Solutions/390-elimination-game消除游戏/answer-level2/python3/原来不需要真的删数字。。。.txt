```python []
if n == 1: return 1

size = n // 2
first = 2
turn = 1
# 先用一个if else，使这一行和下一行之间需要加2 ** turn。因为有时候不需要
while size > 1:
    if size % 2 == 1:
        first += 2 ** turn
    else:
        first = first
    size = size // 2
    turn += 1
    if size > 1:
        first += 2 ** turn
    size = size // 2
    turn += 1
return first
```



