### 解题思路
计数不同即可

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in t:
            if t.count(i) != s.count(i):
                return i
```