
```
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        #递归：从头遍历t，当s的第一个字符==t[i]，判断s[1:]是否是t[i+1:]
        if s == "":
            return True
    
        for i in xrange(0,len(t)):
            if s[0] == t[i]:
                return self.isSubsequence(s[1:],t[i+1:])
            else:
                continue
        return False
```
