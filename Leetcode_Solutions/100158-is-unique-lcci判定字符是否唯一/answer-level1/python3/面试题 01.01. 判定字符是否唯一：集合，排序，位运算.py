### 集合

```python []
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len({*astr}) == len(astr)
```

### 排序

```python []
class Solution:
    def isUnique(self, astr: str) -> bool:
        s = sorted(astr)
        return all(s[i] != c for i, c in enumerate(s[1: ]))
```

### 位运算

```python []
class Solution:
    def isUnique(self, astr: str) -> bool:
        t = 0
        for c in astr:
            if t & (p := 1 << (ord(c) - 97)):
                return False
            t |= p
        return True
```
