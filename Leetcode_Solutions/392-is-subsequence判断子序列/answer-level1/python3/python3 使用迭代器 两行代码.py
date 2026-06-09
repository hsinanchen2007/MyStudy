python3 使用迭代器
```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t = iter(t)
        return all(s1 in t for s1 in s)
```