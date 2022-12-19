### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s:str) -> int:
        t=[]
        maxlen=0
        i=0
        j=0
        while i<len(s):
            if s[i] not in t:
                
                print(i)
                t.append(s[i])
                i=i+1
                maxlen=max(maxlen,len(t))
            else:
                j+=1
                i=t.index(s[i])-1+j
                t=[]
        return maxlen
```