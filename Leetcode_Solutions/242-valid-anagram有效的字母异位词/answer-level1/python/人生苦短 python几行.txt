人生苦短。。。


```
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        if s==t and s=="":
            return True
        return reduce(lambda x,y: x and y,[s.count(it)==t.count(it) for it in set(s)])   

```
