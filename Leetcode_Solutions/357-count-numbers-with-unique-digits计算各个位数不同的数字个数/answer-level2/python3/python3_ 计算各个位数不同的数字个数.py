```python
def countNumbersWithUniqueDigits(n):
    counts = [9,9,8,7,6,5,4,3,2,1]
    res, product = 1, 1
    
    # 超过10位的, 均会重复
    n = n if n <= 10 else 10
    for i in range(n):
        product *= counts[i]
        res += product
    
    return res

print(countNumbersWithUniqueDigits(9))
```