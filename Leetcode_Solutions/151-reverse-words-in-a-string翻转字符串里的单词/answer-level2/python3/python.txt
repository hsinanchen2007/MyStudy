


```
def reverseWords( s: str):
    a = [i for i in s.split(' ')]
    n = 0
    for i in a:
        if i == '':
            n += 1
    for j in range(n):
        a.remove('')
    return ' '.join(a[::-1])
```

