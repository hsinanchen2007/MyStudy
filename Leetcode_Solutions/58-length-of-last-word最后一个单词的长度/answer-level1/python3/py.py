

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0 or s == " ":
            return 0
        else:
            lst = s.split()
            if len(lst) == 0:
                return 0
            return len(lst[-1])
```