### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dict={}
        for i in range(len(s)):
            if s[i] not in dict:
                dict[s[i]]=i
        s1=[]
        for i in s:
            s1.append(dict[i])

        dict = {}
        for i in range(len(t)):
            if t[i] not in dict:
                dict[t[i]] = i
        t1 = []
        for i in t:
            t1.append(dict[i])


        return s1==t1
```