### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        len_s=len(s)
        len_t=len(t)
        if len_s==0:
            return True
        j=0
        for i in range(len_t):
            if t[i]==s[j]:
                j=j+1
            if j==len_s-1  and i+1<len_t and t[i+1]==s[j]:
                return True
        return False
```