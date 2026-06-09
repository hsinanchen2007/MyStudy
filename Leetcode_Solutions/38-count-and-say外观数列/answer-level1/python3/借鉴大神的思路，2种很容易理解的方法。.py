### 1. 使用递归。


```python []
def solve(n):
    if n == 1:
        return "1"

    new_string = solve(n - 1)               # 这里使用了递归
    res = ''
    many = 1
    i = 0
    while i < len(new_string)-1:
        if new_string[i] == new_string[i+1]:
            many += 1
            print(i, new_string[i])
        else:
            res += str(many)
            res += new_string[i]

            many = 1
        i += 1
    # 如果最后2个数字不相等的话，那么while 循环没法取到最后一位。
    # 所以这里需要处理一下最后一位数字的问题。比如 ”11“
    if new_string[-1] != new_string[i]:
        res += "1"
        res += new_string[-1]
    else:
        res += str(many)
        res += new_string[i]

    
    return res
```
### 2. 递归结合itertools.groupBy 
```python
import itertools

def it_solve(n):
    if n == 1:
        return "1"
    res = ""
    for k, g in itertools.groupby(solve(n-1)):
        temp = ''.join(list(g))
        res += str(len(temp))
        res += str(k)
    return res
```
