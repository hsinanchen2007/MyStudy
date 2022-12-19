```python
def compareVersion(version1, version2):
    # 分隔为数组
    v1 = [int(v) for v in version1.split('.')]
    v2 = [int(v) for v in version2.split('.')]
    # 去掉尾部的0
    while v1 and v1[-1] == 0:
        v1.pop()
    while v2 and v2[-1] == 0:
        v2.pop()
    # 为元祖进行比较
    v1, v2 = tuple(v1), tuple(v2)
    
    return 1 if v1 > v2 else 0 if v1 == v2 else -1

print(compareVersion("0.1", "1.1"))
print(compareVersion("1.0.1", "1"))
print(compareVersion("7.5.2.4", "7.5.3"))
print(compareVersion("1.01", "1.001"))
print(compareVersion("1.0", "1.0.0"))
```