题目意思为两个字符串的：偶数位置的字符排序后相同；奇数位置的字符排序后也相同。则为特殊等价字符串组。
```
def numSpecialEquivGroups(self, A: List[str]) -> int:
    res = set()
    for sub in A:
        sub = ''.join(sorted(sub[::2]) + sorted(sub[1::2]))
        res.add(sub)
    return len(res)
```