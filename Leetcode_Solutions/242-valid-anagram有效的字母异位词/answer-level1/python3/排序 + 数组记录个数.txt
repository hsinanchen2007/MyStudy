思路一：排序

时间复杂度：$O(nlogn)$

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```

思路二：桶记录个数

我们先统计`s`字母的个数，再看看`t`里面也有这些

时间复杂度：$O(n)$

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        counts = [0] * 26
        for a in s:
            counts[ord(a) - ord("a")] += 1
        for b in t:
            # 说明两个不一样
            if counts[ord(b) - ord("a")] <= 0:
                return False
            counts[ord(b) - ord("a")] -= 1
        return True
```

