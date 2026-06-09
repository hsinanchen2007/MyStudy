```python
def hasGroupsSizeX(deck):
    # 获取出现次数
    counter = list(sorted(set(collections.Counter(deck).values())))
    min_count = min(counter)
    # 如果存在出现一次, 则返回错误
    if 1 in counter:
        return False
    for i in range(2, min_count + 1):
        # 从2开始, 判断是否均可除尽
        if all([c % i == 0 for c in counter]):
            return True
    return False

print(hasGroupsSizeX([1,2,3,4,4,3,2,1]))
```