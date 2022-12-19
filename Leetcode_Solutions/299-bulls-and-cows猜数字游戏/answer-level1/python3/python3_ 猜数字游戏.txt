```python
def getHint(secret, guess):
    """
        1. 先计算相等的字符a的个数.
        2. 把不相等的字符进行数量的统计, 然后计算b的个数
    """
    a, b, s1, s2 = 0, 0, [], []
    for i in range(len(secret)):
        if secret[i] == guess[i]:
            a += 1
        else:
            s1.append(secret[i])
            s2.append(guess[i])
    counter1,counter2 = collections.Counter(s1), collections.Counter(s2)
    for k in counter1.keys():
        if k in counter2:
            b += min(counter1[k], counter2[k])
    
    return f'{a}A{b}B'

print(getHint("1807", "7810"))
print(getHint("1123", "0111"))
```