### 解题思路
emmm好占内存，好慢啊

### 代码

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): return False
        dic = {}
        for i in range(len(s)):
            dic[s[i]] = dic.get(s[i], 0) + 1
            dic[t[i]] = dic.get(t[i], 0) - 1
        # if list(dic.values()) == [0] * len(dic): #80ms
        #     return True
        # else:
        #     return False
        for item in dic.values(): #60ms
            if item != 0:
                return False
        return True
        
```