```python
def twoSum(numbers, target):
    # i, j指向数组的首尾, 相加. 如果小于target, 则i自增, 大于则j自减;
    # 等于, 则返回索引
    i, j = 0, len(numbers) - 1
    while numbers[i] + numbers[j] != target:
        if numbers[i] + numbers[j] < target:
            i += 1
        else:
            j -= 1
    return [i + 1, j + 1]

print(twoSum([2, 7, 11, 15], 9))
```