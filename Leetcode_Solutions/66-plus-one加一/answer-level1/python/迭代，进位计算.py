如果加1之后不用进位，结束计算，直接返回digits；
如果加1之后需要进位，该位上变成digits[i] % 10，上一位继续进行加1运算，按此方式迭代...
需要单独考虑99 + 1这种情况，这种情况数字的位数会增加，这时需要在digits前面插入一位1。

```
i = len(digits) - 1
while i >= 0:
    digits[i] += 1
    if digits[i] < 10:
        return digits
    else:
        digits[i] %= 10 
        i -= 1
if i == -1:    # 位数需要增加一位
    digits.insert(0, 1)
return digits
```
