递归解法

```python []
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) ==0:
            return ""
        a = []
        for i in strs:
            if not i:
                return ""
            if len(a)==0:
                a.append(i[0])
            if i[0] not in a:
                return ""
        return a[0] + self.longestCommonPrefix([i[1:] for i in strs])    
```

        