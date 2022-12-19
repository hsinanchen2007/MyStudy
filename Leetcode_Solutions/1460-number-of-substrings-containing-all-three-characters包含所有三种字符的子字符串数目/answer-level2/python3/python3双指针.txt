### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        mp={'a':0,'b':0,'c':0}
        count=0
        i=0
        for j in range(len(s)):
            mp[s[j]]+=1
            while  mp['a']>0 and mp['b']>0 and mp['c']>0:
                count+=len(s)-j
                mp[s[i]]-=1
                i+=1
        return count
```