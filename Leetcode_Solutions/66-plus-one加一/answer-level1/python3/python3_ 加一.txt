```python
def plusOne(digits):
    # 将digits进行倒序, 最后在倒序, 便于理解
    # 将k初始化为1, 就相当于加1
    digits, k = digits[::-1], 1
    for i, d in enumerate(digits):
        # 如果当前值不大于10, 说明无需继续下去, 并设置k=0
        if d + k < 10:
            digits[i] = d + k
            k = 0
            break
        else:
            # 将k设置为1, 并且当前索引设置为0(因为加1, 所以肯定为0)
            k, digits[i] = 1, 0
    # 说明最后还存在进位
    if k == 1:
        digits.append(1)
        
    return digits[::-1]

print(plusOne([1,2,3]))
print(plusOne([4,3,2,1]))
print(plusOne([9,9,9]))
```