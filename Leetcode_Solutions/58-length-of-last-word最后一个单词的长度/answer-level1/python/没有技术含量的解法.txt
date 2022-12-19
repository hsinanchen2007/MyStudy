一、使用库函数
```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        #去除右端空格
        s=s.rstrip()
        return len(s[s.rfind(" ")+1:])
```

二、遍历
```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        l=len(s)
        j=0
        for i in range(l):
            if s[l-i-1]==" ":
                if j!=0:
                    return j
                continue
            else:
                j+=1
        return j
```
