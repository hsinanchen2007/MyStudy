```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter
        p, q = Counter(s), Counter(t)
        return p == q
```
计数器本身也是利用了hash的思想，这里直接用计数器作对比，其他的工作就由经大神优化过的python底层完成吧

