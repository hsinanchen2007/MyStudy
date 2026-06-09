代码块
```
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        num=0
        while s:
            s,num=self.function(s,num)
        return num
    def function(self,s,num):
        for i in range(1,len(s),2):
            if s[:i+1].count('R')==s[:i+1].count('L'):
                num+=1
                s=s[i+1:]
                break
        return s,num
```
