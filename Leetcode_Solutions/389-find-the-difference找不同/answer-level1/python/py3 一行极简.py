### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return [x for x in t if t.count(x)-s.count(x)==1][0]
```