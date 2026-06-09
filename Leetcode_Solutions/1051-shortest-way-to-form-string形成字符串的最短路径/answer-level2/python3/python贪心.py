本来想用暴力，无奈时间超了：
1. 计算出source的所有子序列，按照子序列长度从大到小排序，存入list
2. 遍历子序列list，去和target匹配。 匹配上了就截断target， num++

计算所有子序列用下面这种方法：

```
n = len(source)
masks = [1 << j for j in range(n)]
for i in range(2**n):
    yield ''.join([source[j] for j in range(n) if (masks[j] & i)])
```

改成下面这种解法，通过：
用t遍历target，t去和source匹配，若匹配上：target截去t， source截去t及之前的子串；当source变为空或targe为空，或新的t不在source中，说明已经达到最大匹配。 num++
```
        num: int = 0
        new_source: str = source
        while len(target) > 0:
            t = target[0]
            # 有元素不在source中，直接返回-1
            if t not in source:
                return -1
            # 当前元素不在new_source中，说明上次已经匹配到最长子串， num++。
            if t not in new_source:
                num += 1
                new_source = source
            loc = new_source.index(t)
            new_source = new_source[loc + 1:]
            target = target[1:]
            # new_source被消耗完，说明当前已经匹配到最长子串，num++
            if not new_source:
                num += 1
                new_source = source
            # new_source还有，但target被消耗完，说明当前已经匹配到最长子串,num++
            elif not target:
                num += 1
        return num

```