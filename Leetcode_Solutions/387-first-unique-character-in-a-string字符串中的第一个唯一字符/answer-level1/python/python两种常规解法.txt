```
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        l=[]
        y=''
        t=0
        for i in s:
            if i not in l:
                l.append(i)
        for i in range(len(l)):
            t=0
            for j in range(len(s)):
                if l[i]==s[j]:
                    t=t+1
            if t==1:
                y=str(l[i])
                break
        if y=='':
            return -1
        for j in range(len(s)):
                if y==s[j]:
                       return j
```
```
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        g=s
        for i in range(len(g)):
            if len(s.replace(g[i],''))==len(s)-1:
                return i
            else:
                s=s.replace(g[i],'')
        return -1
```
