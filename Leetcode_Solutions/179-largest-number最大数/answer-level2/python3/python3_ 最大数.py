```python
import functools
def largestNumber(nums):
    # 倒序比较
    def cmp(a, b):
        if int(f'{b}{a}') > int(f'{a}{b}'):
            return 1
        elif int(f'{b}{a}') == int(f'{a}{b}'):
            return 0
        else:
            return -1
    # 将nums进行比较
    r = ''.join(sorted(map(str, nums), key=functools.cmp_to_key(cmp)))
    # 去掉前面的0
    i = 0
    while i < len(r) and r[i] == '0':
        i += 1
    return r[i:] if r[i:] else '0'
    
print(largestNumber([10,2]))
print(largestNumber([3,30,34,5,9]))
print(largestNumber([3,30,34,5,9]))
print(largestNumber([0,0]))
```