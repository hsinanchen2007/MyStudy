
### 代码
```python
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = dict()
        for i in range(len(s)):
            if s[i] not in dic: dic[s[i]] = t[i]
            elif dic[s[i]] != t[i]:return False
        dic2 = dict()
        for i in range(len(s)):
            if t[i] not in dic2: dic2[t[i]] = s[i]
            elif dic2[t[i]] != s[i]:return False
        return True            
```