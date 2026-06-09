![image.png](https://pic.leetcode-cn.com/26d4079f99479af3583c46c3183615a448006f9b66b4c1b6291deb5ae6ddc951-image.png)

```
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        sdic = {}
        for char in s:
            if char in sdic:
                sdic[char] += 1
            else:
                sdic[char] = 1
        for char in t:
            if char in sdic:
                if sdic[char] == 1:
                    sdic.pop(char)
                else:
                    sdic[char] -= 1
            else:
                return False
        return sdic == {}
```
