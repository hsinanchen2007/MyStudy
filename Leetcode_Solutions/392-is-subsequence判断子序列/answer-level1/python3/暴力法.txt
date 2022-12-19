### 解题思路
简单明了了

### 代码

```python3
class Solution(object):
    def isSubsequence(self, s, t):    
       
        i,j = 0,0
        while i<len(s) and j<len(t):
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        return i==len(s)


```