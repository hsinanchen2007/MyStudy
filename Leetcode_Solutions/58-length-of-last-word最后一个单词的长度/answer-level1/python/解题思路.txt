### 解题思路
直接用split分隔开

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s=="" or s==" ":
            return 0
        s=s.rstrip()
        ss=s.split(" ")
        if ss[-1]!=" ":
            return len(ss[-1])
        return 0
```