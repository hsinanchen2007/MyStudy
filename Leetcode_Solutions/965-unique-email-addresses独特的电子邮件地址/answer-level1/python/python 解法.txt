### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        m = {}
        for i in emails:
            l = i.split('@')
            g = l[0].split('+')
            g = g[0].replace('.','')
            w = g+'@'+l[1]
            if w not in m:
                m[w]=1
            else:
                m[w]+=1
        return len(m)
```