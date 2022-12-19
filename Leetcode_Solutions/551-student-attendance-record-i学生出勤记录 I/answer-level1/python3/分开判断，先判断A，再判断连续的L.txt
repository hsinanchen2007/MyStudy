
### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        if s.count("A") > 1:
            return False
        i = 0
        j = 0
        count = 0
        while j < len(s):
            if s[j] != "L":
                j += 1
                i = j
            else:
                j += 1
            if j - i >2:
                return False
        return True
```