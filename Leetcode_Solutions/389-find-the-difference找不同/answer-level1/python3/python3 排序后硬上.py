### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s=list(s)
        t=list(t)
        s=sorted(s)
        t=sorted(t)
        for i in range(len(s)):
            if s[i]!=t[i]:
                return t[i]
        return t[-1] 
```