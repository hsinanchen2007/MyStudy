先用任意数字检验一下，发现如果是快乐数 最终会收敛到1， 如果不是快乐数 最终会出现4 16 37 58 89 145 42 20循环
    
```
while True:
    n = sum([int(i)**2 for i in str(n)])
    if n == 4:
        return False
    if n == 1:
        return True
```

